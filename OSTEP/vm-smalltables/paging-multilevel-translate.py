from optparse import OptionParser
import random


# This makes Python2 and Python3 behave the same
def random_seed(seed):
    try:
        random.seed(seed, version=1)
    except:
        random.seed(seed)
    return


class OS:
    def __init__(self):
        # 4K physical memory (128 pages)
        self.page_size = 32
        self.phys_pages = 128
        self.phys_mem = self.page_size * self.phys_pages
        self.va_pages = 1024
        self.va_size = self.page_size * self.va_pages
        self.pte_size = 1
        self.page_bits = 5      # log of page size

        # OS tracks
        self.used_pages = []
        self.used_pages_count = 0
        self.max_page_count = int(self.phys_mem / self.page_size)

        # No pages used yet
        for i in range(0, self.max_page_count):
            self.used_pages.append(0)

        # Set contents of memory to 0
        self.memory = []
        for i in range(0, self.phys_mem):
            self.memory.append(0)
        
        # Associative array of pdbr's (indexed by PID)
        self.pdbr = {}

        # Mask is 11111 00000 00000 --> 0111 1100 0000 0000
        self.PDE_MASK = 0x7c00
        self.PDE_SHIFT = 10

        # 00000 11111 00000 -> 000 0011 1110 0000
        self.PTE_MASK = 0x03e0
        self.PTE_SHIFT = 5

        self.VPN_MASK = self.PDE_MASK | self.PTE_MASK
        self.VPN_SHIFT = self.PTE_SHIFT

        # Grabs the last five bits of a virtual address
        self.OFFSET_MASK = 0x1f

    def find_free(self):
        """
        Find a free page by using this randomized algorithm
        """

        assert(self.used_pages_count < self.max_page_count)
        
        look = int(random.random() * self.max_page_count)

        while self.used_pages[look] == 1:
            look = int(random.random() * self.max_page_count)
        
        self.used_pages_count = self.used_pages_count + 1
        self.used_pages[look] = 1

        return look

    def init_page_dir(self, which_page):
        which_byte = which_page << self.page_bits

        for i in range(which_byte, which_byte + self.page_size):
            self.memory[i] = 0x7f
    
    def init_page_table_page(self, which_page):
        self.init_page_dir(which_page)
    
    def get_page_table_entry(self, virtual_addr, pte_page, print):
        pte_bits = (virtual_addr & self.PTE_MASK) >> self.PTE_SHIFT
        pte_addr = (pte_page << self.page_bits) | pte_bits
        pte = self.memory[pte_addr]
        valid = (pte & 0x80) >> 7
        pfn = (pte & 0x7f)

        if print:
            print('    --> pte index:0x%x [decimal %d] pte contents:0x%x (valid %d, pfn 0x%02x [decimal %d])' % (pte_bits, pte_bits, pte, valid, pfn, pfn))
        
        return (valid, pfn, pte_addr)

    def proc_alloc(self, pid, num_pages):
        # Need a PDBR (page directory base register): find one somwhere in memory
        page_dir = self.find_free()
        # print("**ALLOCATE** Page dir: ", page_dir)
        self.pdbr[pid] = page_dir
        self.init_page_dir(page_dir)

        used = {}

        for vp in range(0, self.va_pages):
            used[vp] = 0
        
        allocated_vps = []

        for vp in range(0, num_pages):
            vp = int(random.random() * self.va_pages)

            while used[vp] == 1:
                vp = int(random.random() * self.va_pages)
            
            assert(used[vp] == 0)
            used[vp] = 1
            allocated_vps.append(vp)
            pp = self.find_free()
            # print('**ALLOCATE** page', pp)
            # print('  trying to map vp:%08x to pp:%08x' % (vp, pp))
            self.allocate_virtual_page(pid, vp, pp)
            self.fill_page(pp)

        return allocated_vps

    def memory_dump(self):
        for i in range(0, int(self.phys_mem / self.page_size)):
            print('page %3d: ' % i, end='')

            for j in range(0, self.page_size):
                print('%02x' % self.memory[(i * self.pageSize) + j], end='')
            
            print('')
    
    def get_PDBR(self, pid):
        return self.pdbr[pid]

    def get_value(self, addr):
        return self.memory[addr]


parser = OptionParser()
parser.add_option('-s', '--seed', default=0, help='the random seed', action='store', type='int', dest='seed')

(options, args) = parser.parse_args()

print('ARG seed', options.seed)
print('ARG allocated', options.allocated)
print('ARG num', options.num)
print('')

random_seed(options.seed)

# Exercise starts here
os = OS()
used = os.proc_alloc(1, options.allocated)

os.memory_dump()
