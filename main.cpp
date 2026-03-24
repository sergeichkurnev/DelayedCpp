#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>


uint64_t getAddress(uint32_t instr, const std::vector<uint64_t>& regs) //Here we'll decode instruction
{
    uint32_t opcode = (instr >> 22) & 0x3FF; //in my opinion, the fastest way is using the arithmetic shift    
    uint32_t offset = (instr >> 10) & 0xFFF;     
    uint32_t src = (instr >> 5) & 0x1F;      
 
    uint64_t address = regs[src] + offset;
    return address;
}

int main() 
{

    uint32_t instr1 = 0x39400002;
    uint32_t instr2 = 0xb9419083;

    // values of registers
    std::vector<uint64_t> regs = 
    {
        0xffffb3f767d0,
        0x71018330,
        0xffffc7a82219,
        0x71018945,
        0x67a37750
    };

    // getting adresses
    uint64_t addr1 = getAddress(instr1, regs);
    uint64_t addr2 = getAddress(instr2, regs);

    //distance:
    uint64_t distance = (addr1 > addr2) ? (addr1 - addr2) : (addr2 - addr1); // we did it due to oferfloating unsigned numbers
    // i'm against ternary operators, but i used it because it,s short and understandable here
    std::cout << distance << std::endl;

    return 0;
}