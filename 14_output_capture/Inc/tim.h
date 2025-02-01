/*
 * tim.h
 *
 *  Created on: Jan 29, 2025
 *      Author: last_knight
 */

#ifndef TIM_H_
#define TIM_H_

void pa5_af_mode(void);
void pa6_af_mode(void);

void tim2_1hz_init(void);
void tim2_output_compare(void);
void tim3_input_capture(void);

#define SR_UIF              (1UL<<0)
#define CR_CC1IF             (1UL<<1)

#endif /* TIM_H_ */
