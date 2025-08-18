// Some important bit wise tricks
/*
! Check for even or odd number
? Check for lsb
    * (x & 1) => 1 means odd, 0 means even

! Check for power of two
    * (x & (x-1));  => 0 means yes, 1 means no

! Check right most set bit
    * (x & -x);
        example, 6 = 110
                -6 = 010
            (6 & -6) => (110 & 010) = 2(010)

! Playing with kth bit
Case 1
? Check if kth bit is set or not
    *  X & (1 << k);

Case 2
? Toggle the kth bit
    * X ^ (1 << k);

Case 3
? Set the kth bit
    * X | (1 << k);

Case 4
? Unset the kth bit
    * X & ~(1 << k);


! Multiply or divide a number by 2^k
? Divide
    * x >> k;
        eg divide by 2, so k = 1
            => x >> 1

? Multiply
    * x << k;
        eg multiply by 2, so k = 1
            => x << 1


! Find (x % 2^k)
    without using modulo operator
    * x & ((1 << k) - 1);

! Swapping without using temp variable
    for val x, y
    * x = x ^ y
    * y = x ^ y
    * x = x ^ y
    values are swapped

! Property
    ? If no of set bits in A = x
    ? Ans no of set bits in B = y
    ? no of set bits in (A ^ B) = z

    then
    z is even if x + y is even
        and
    z is odd if x + y is odd

    eg, a = 6, b = 8
    then, a = 6 = 110 => x = 2 set bits
    and, b = 8 = 1000 => y = 1 set bit

    then z is odd or even can be checked form sum of a and b, whether sum is even or odd

! Add two number without using + operator

    ? A + B = (A ^ B) + 2(A & B)

    explaination
    A ^ B → gives the bits which are different in A and B (no carry part).
    A & B → gives the bits which are common in A and B (carry part).
    Since carry has to be added in the next higher position, we multiply it by 2 (i.e. left shift by 1).
    => A + B = (A ^ B) + 2(A & B)
    `
        A = 1001 (9)
        B = 0011 (3)
        A ^ B = 1010 (10)   // uncommon bits
        A & B = 0001 (1)
        2(A & B) = 0010 (2) // shifted carry
        Result = 1010 + 0010 = 1100 (12)


! Using C++ STL
In built stl class to deal with bit is => bitset

bitset<bit_range>bit(num);

? to check set bit at a position
    * bit.test(pos)

? to set a bit at a position
    * bit.set(pos, bit)
        eg bit.set(3, 0)

? to flip bit at a position
    * bit.flip(pos);

? to find size
    * bit.size();

? to find count of all set bits
    * bit.count();

? to check all bits are 1
    * bit.all();

? to check atleast one bit is set
    * bit.any();

? to check all bits are unset
    * bit.none();

? to get integer form of bits
    * bit.to_ullong()   ==> gives unsigned long long
    * bit.to_ulong()    ==> gives unsigned long

? to get string form of bits
    * bit.to_string();
*/
