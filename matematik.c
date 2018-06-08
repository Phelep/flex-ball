#define ESC 0x1B
#include "matematik.h"

int32_t sinus(int v){
//    if (v<0){
//        int v1=511+v;
////        return SIN[v1];
//        /*printFix(expand((SIN[v1])));*/
//    }
//    if (v>511){
//            int v2=v & 0x1FF;
////            return SIN[v2];
//           /* printFix(expand(SIN[v2]));*/
//
//    }
//    else{
//    /*printFix(expand(SIN[v]));*/


return SIN[v & 0x1FF];
}

int32_t cosinus(int v){
    int v90 = v+128;
    return sinus(v90);

}




