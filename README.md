# 5813Project3
John Kim <br />
In this project, I attempted to meet these goals
1. Investigated DMA functionality in KL25z microprocessor and compared it with other memory assignment techniques
2. Hardware Abstraction Layer for Serial Port Interface
3. Data transmission using nRF module

Memory operation summary
1. In terms of performance in BBB, my memory without optimization is least efficient, while library memory operation is the most efficient.
2. In Kl25z, same holds true except that DMA outperforms all other memory operation by magnitudes.
3. According to my test program, 32bit transfer has quite a bit of performance benefit. This difference is more noticeable with increase in transfer size.
4. Stack usage is quite consistent across the board since I am writing to heap memory, not the stack.
5. BBB outperforms Kl25z in library and my memory function. 
