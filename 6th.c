#include <reg51.h>
sbit ir1=P1^0;
sbit ir2=P1^1;
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
void lcdcmd (unsigned char);
void lcddat (unsigned char);
void lcddis (unsigned char*, unsigned char);

void conversion(unsigned char,unsigned char);
void delay();
void delay2();
void main(){
    unsigned char v1,v2;

    lcdcmd(0x38);
    lcdcmd(0x10);
    lcdcmd(0x0c);
    lcdcmd(0x80);
    lcddis("WELCOME TO",10);
    lcdcmd(0xc0);
    lcddis("VISITOR COUNTER", 15);
    while(1){
			
        if(ir1==0){
            delay2();
            if(ir1==0){
                v1=v1+1;
								if(v1==1){
									lcdcmd(0x01);
								}
                conversion(v2,v1);
            }
        }
        if(ir2==0){
            delay2();
            if(ir1==0){
                v2=v2+1;
                conversion(v2,v1);
            }
        }
    }
}
void lcdcmd(unsigned char val){
    P3=val;
    rs=0;
    rw=0;
    en=1;
    delay();
    en=0;
}
void lcddat(unsigned char dat){
    P3=dat;
    rs=1;
    rw=0;
    en=1;
    delay();
    en=0;
}
void lcddis(unsigned char *s, unsigned char r){
    unsigned char v3;
    for(v3=0;v3<r;v3++){
        lcddat(s[v3]);
    }
}
void delay(){
    unsigned int v4;
    for(v4=0;v4<4000;v4++);
}
void delay2(){
    unsigned int v4,v11;
    for(v4=0;v4<35;v4++){
        for(v11=0;v11<4000;v11++);
    };
}

void conversion(unsigned char ext,unsigned char ent) {
	unsigned char v8, v9, v10,v15;
	lcdcmd(0x80);
	lcddis("Total Entry:",12);
	lcdcmd(0x8c);
	v8 = ent;
	v15=v8/100;
	v9 = v8/10;
	v9=v9%10;
	v10 = v8%10;
	v15=v15|0x30;
	v9 = v9|0x30;
	v10 = v10|0x30;
	lcddat(v15);
	lcddat(v9);
	lcddat(v10);

	lcdcmd(0xc0);
	lcddis("INSIDE:",7);
	v8 = ent-ext;
	v15=v8/100;
	v9 = v8/10;
	v9=v9%10;
	v10 = v8%10;
	v15=v15|0x30;
	v9 = v9|0x30;
	v10 = v10|0x30;
	lcdcmd(0xc8);
	lcddat(v15);
	lcddat(v9);
	lcddat(v10);
}