/** Tag family with 242 distinct codes.
    bits: 25,  minimum hamming: 4,  minimum complexity: 8

    Max bits corrected       False positive rate
            0                    0.000721 %
            1                    0.018752 %
            2                    0.235116 %
            3                    1.893914 %

    Generation time: 72.585000 s

    Hamming distance between pairs of codes (accounting for rotation):

       0  0
       1  0
       2  0
       3  0
       4  0
       5  0
       6  0
       7  2076
       8  4161
       9  5299
      10  6342
      11  5526
      12  3503
      13  1622
      14  499
      15  114
      16  16
      17  3
      18  0
      19  0
      20  0
      21  0
      22  0
      23  0
      24  0
      25  0
**/

#pragma once

namespace AprilTags {

const unsigned long long t25h4[] =
  {  
	0x2cd5f4L,0x2cd5ceL, 0x2CD6D6L, 0x2cd4e7L,0x2cd6ecL, 0x2cd4ddL,0x2cd6b5L,0x2cd597L,0x2cd4beL,0x2cd79cl,0x2cd7c5L

};

static const TagCodes tagCodes25h4 = TagCodes(25,4, t25h4, sizeof(t25h4)/sizeof(t25h4[0]));

}
