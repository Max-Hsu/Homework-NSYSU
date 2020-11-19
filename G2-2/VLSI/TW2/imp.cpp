#include <iostream>

using namespace std;
int total_transistor;
bool p0,p1,p2,p3,p4,p5,p6,p7;
bool g0,g1,g2,g3,g4,g5,g6,g7;

bool t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18;
bool g1_0,g3_2,g3_0,g5_4,g7_6,g7_4,g7_0,g5_0,g2_0,g4_0,g6_0;
bool p3_2,p5_4,p7_6,p7_4;
bool a_I[8],b_I[8],o[9];
int8_t a,b;
int out;
void numToBool(){
    for(int i=0;i<8;i++){
        a_I[i] = a%2;
        a = a>>1;
        b_I[i] = b%2;
        b = b>>1;
    }
}
void boolToNum(){

}
bool nand_O(bool a,bool b){
    total_transistor+=4;
    return !(a&&b);
}
bool and_O(bool a,bool b){
    total_transistor+=6;
    return a&&b;
}
bool nor_O(bool a,bool b){
    total_transistor+=4;
    return !(a||b);
}
bool or_O(bool a,bool b){
    total_transistor+=6;
    return (a||b);
}
bool xor_O(bool a,bool b){
    total_transistor+=12;
    return (a^b);
}
bool inv_O(bool a){
    total_transistor+=2;
    return !a;
}
int test(int a_x , int b_x){
    a = a_x;
    b = b_x;
    numToBool();
    
    p0=xor_O(a_I[0],b_I[0]);
    p1=xor_O(a_I[1],b_I[1]);
    p2=xor_O(a_I[2],b_I[2]);
    p3=xor_O(a_I[3],b_I[3]);
    p4=xor_O(a_I[4],b_I[4]);
    p5=xor_O(a_I[5],b_I[5]);
    p6=xor_O(a_I[6],b_I[6]);
    p7=xor_O(a_I[7],b_I[7]);
    g0=and_O(a_I[0],b_I[0]);
    g1=nand_O(a_I[1],b_I[1]);
    g2=nand_O(a_I[2],b_I[2]);
    g3=nand_O(a_I[3],b_I[3]);
    g4=nand_O(a_I[4],b_I[4]);
    g5=nand_O(a_I[5],b_I[5]);
    g6=nand_O(a_I[6],b_I[6]);
    g7=nand_O(a_I[7],b_I[7]);

    t1=nand_O(g0,p1);
    t2=nand_O(inv_O(g2),p3);
    t3=nand_O(inv_O(g4),p5);
    t4=nand_O(inv_O(g6),p7);

    p3_2 = and_O(p2,p3);
    p5_4 = and_O(p4,p5);
    p7_6 = and_O(p6,p7);

    g1_0 = nand_O(t1,g1);
    g3_2 = and_O (t2,g3);
    g5_4 = and_O (t3,g5);
    g7_6 = and_O (t4,g7);

    t5 = nand_O(g1_0,p3_2);
    t6 = nand_O(inv_O(g5_4),p7_6);

    p7_4 = and_O(p7_6,p5_4);

    g3_0 = nand_O(t5,g3_2);
    g7_4 = and_O (t6,g7_6);

    t7 = nand_O(g3_0,p7_4);
    
    g7_0 = nand_O(t7,g7_4);

    t8 = nand_O(g3_0,p5_4);

    g5_0 = nand_O(t8,g5_4);

    t9  = nand_O(g1_0,p2);
    t10 = nand_O(g3_0,p4);
    t11 = nand_O(g5_0,p6);

    g2_0 = nand_O(t9,g2); 
    g4_0 = nand_O(t10,g4); 
    g6_0 = nand_O(t11,g6); 

    t12 = xor_O(g0,p1);
    t13 = xor_O(g1_0,p2);
    t14 = xor_O(g2_0,p3);
    t15 = xor_O(g3_0,p4);
    t16 = xor_O(g4_0,p5);
    t17 = xor_O(g5_0,p6);
    t18 = xor_O(g6_0,p7);

    o[0] = p0;
    o[1] = t12;
    o[2] = t13;
    o[3] = t14;
    o[4] = t15;
    o[5] = t16;
    o[6] = t17;
    o[7] = t18;
    o[8] = g7_0; //cout
    
    /*
    cout<<"\t";
    for(int i=7;i>=0;i-=1){
        cout<<a_I[i]<<"\t";
    }
    cout<<"\n";
    cout<<"\t";
    for(int i=7;i>=0;i-=1){
        cout<<b_I[i]<<"\t";
    }
    cout<<"\n";
    for(int i=8;i>=0;i-=1){
        cout<<o[i]<<"\t";
    }    
    */
    out = 0;
    for(int i=8;i>=0;i-=1){
        out = out<<1;
        if(o[i]){
            out+=1;   
        }
    }
    
    if((a_x+b_x)!=out){
        cout<<"err\n";
    }
    //cout<<"\n";
    //cout<<a_x+b_x<<"\t"<<out<<"\n";
}
int test_v(int a_x , int b_x){
    a = a_x;
    b = b_x;
    numToBool();
    
    p0=xor_O(a_I[0],b_I[0]);
    p1=xor_O(a_I[1],b_I[1]);
    p2=xor_O(a_I[2],b_I[2]);
    p3=xor_O(a_I[3],b_I[3]);
    p4=xor_O(a_I[4],b_I[4]);
    p5=xor_O(a_I[5],b_I[5]);
    p6=xor_O(a_I[6],b_I[6]);
    p7=xor_O(a_I[7],b_I[7]);
    g0=and_O(a_I[0],b_I[0]);
    g1=nand_O(a_I[1],b_I[1]);
    g2=nand_O(a_I[2],b_I[2]);
    g3=nand_O(a_I[3],b_I[3]);
    g4=nand_O(a_I[4],b_I[4]);
    g5=nand_O(a_I[5],b_I[5]);
    g6=nand_O(a_I[6],b_I[6]);
    g7=nand_O(a_I[7],b_I[7]);

    t1=nand_O(g0,p1);
    t2=nand_O(inv_O(g2),p3);
    t3=nand_O(inv_O(g4),p5);
    t4=nand_O(inv_O(g6),p7);

    p3_2 = and_O(p2,p3);
    p5_4 = and_O(p4,p5);
    p7_6 = and_O(p6,p7);

    g1_0 = nand_O(t1,g1);
    g3_2 = and_O (t2,g3);
    g5_4 = and_O (t3,g5);
    g7_6 = and_O (t4,g7);

    t5 = nand_O(g1_0,p3_2);
    t6 = nand_O(inv_O(g5_4),p7_6);

    p7_4 = and_O(p7_6,p5_4);

    g3_0 = nand_O(t5,g3_2);
    g7_4 = and_O (t6,g7_6);

    t7 = nand_O(g3_0,p7_4);
    
    g7_0 = nand_O(t7,g7_4);

    t8 = nand_O(g3_0,p5_4);

    g5_0 = nand_O(t8,g5_4);

    t9  = nand_O(g1_0,p2);
    t10 = nand_O(g3_0,p4);
    t11 = nand_O(g5_0,p6);

    g2_0 = nand_O(t9,g2); 
    g4_0 = nand_O(t10,g4); 
    g6_0 = nand_O(t11,g6); 

    t12 = xor_O(g0,p1);
    t13 = xor_O(g1_0,p2);
    t14 = xor_O(g2_0,p3);
    t15 = xor_O(g3_0,p4);
    t16 = xor_O(g4_0,p5);
    t17 = xor_O(g5_0,p6);
    t18 = xor_O(g6_0,p7);

    o[0] = p0;
    o[1] = t12;
    o[2] = t13;
    o[3] = t14;
    o[4] = t15;
    o[5] = t16;
    o[6] = t17;
    o[7] = t18;
    o[8] = g7_0; //cout
    
    
    cout<<"\t";
    for(int i=7;i>=0;i-=1){
        cout<<a_I[i]<<"\t";
    }
    cout<<"\n";
    cout<<"\t";
    for(int i=7;i>=0;i-=1){
        cout<<b_I[i]<<"\t";
    }
    cout<<"\n";
    for(int i=8;i>=0;i-=1){
        cout<<o[i]<<"\t";
    }    
    
    out = 0;
    for(int i=8;i>=0;i-=1){
        out = out<<1;
        if(o[i]){
            out+=1;   
        }
    }
    
    cout<<"\n";
    cout<<"p7\t"<<p7<<"\t"<<"g7\t"<<g7<<"\t"<<"t4\t"<<t4<<"\t"<<"p7_6\t"<<p7_6<<"\t"<<"g7_6\t"<<g7_6<<"\n"<<"t6\t"<<t6<<"\t"<<"p7_4\t"<<p7_4<<"\t"<<"g7_4\t"<<g7_4<<"\t"<<"t7\t"<<t7<<"\t"<<"g7_0\t"<<g7_0<<"\n";
    cout<<"g5_4"<<g5_4<<"\n";
    cout<<a_x+b_x<<"\t"<<out<<"\n";
}
int main(){
    /*
    int x,y;
    for(x = 0; x<256;x++){
        for(y = 0 ;y<256;y++){
            test(x,y);
            if(x==0 && y==0){
                cout<<total_transistor<<"\n";
            }
        }
    }*/

    test_v(255,0);
    cout<<"bye";
}