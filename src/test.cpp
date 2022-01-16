#include <bits/stdc++.h>
#include <stdio.h>

int main(){

    uint16_t hoge = 0x000F;
    uint8_t aaa = 0x12;
    // hoge |= (hoge & 0x0f) << 12;
    aaa |= (hoge & 0x0f) << 12;
    // hoge |= (aaa & 0x0f);

    std::cout << std::hex << hoge << std::endl;

    return 0;
}

