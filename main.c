#include<16F819.h>

//INTRC_IO//内部クロックを使用してクロック用ピンをＩＯとして使用できるようにする設定
//「NOMCLR」を追加すると、「リセット端子を使用しない」設定となり、ICD2のMCLRを外さなくてもPICが動作する

#fuses INTRC_IO,NOPUT, NOWDT, NOLVP, NOBROWNOUT,NOPROTECT//,NOMCLR
#use delay(CLOCK=8000000)//4MHz




void main(void)
{
	int c=0;
	int duty=0;
	set_tris_b(0x80);// 

	setup_timer_2(T2_DIV_BY_1,0xFF,1);
	setup_ccp1(CCP_PWM);
	set_pwm1_duty(0);
	duty = 0;

	while(true){
		for(duty=0;duty<0xFF;duty++){
			delay_ms(50);
			set_pwm1_duty(duty);
		}
		output_high(PIN_A1);
		delay_ms(3000);
		set_pwm1_duty(0);
		output_low(PIN_A1);
		delay_ms(3000);
	}
}