/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 08:21:18 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/19 08:21:48 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BURN_H
# define BURN_H

# define A 0x960000, 0x970000, 0x980000, 0x980000, 0x990000, 0x9A0000
# define B 0x9A0000, 0x9B0000, 0x9C0000, 0x9C0000, 0x9D0000, 0x9E0000
# define C 0x9E0000, 0x9F0000, 0xA00000, 0xA00000, 0xA10000, 0xA10000
# define D 0xA20000, 0xA30000, 0xA30000, 0xA40000, 0xA50000, 0xA50000
# define E 0xA60000, 0xA60000, 0xA70000, 0xA70000, 0xA80000, 0xA90000
# define F 0xA90000, 0xAA0000, 0xAA0000, 0xAB0000, 0xAC0000, 0xAC0000
# define G 0xAD0000, 0xAD0000, 0xAE0000, 0xAE0000, 0xAF0000, 0xAF0000
# define H 0xB00000, 0xB00000, 0xB10000, 0xB10000, 0xB20000, 0xB20000
# define I 0xB30000, 0xB30000, 0xB40000, 0xB40000, 0xB50000, 0xB50000
# define J 0xB60000, 0xB60000, 0xB70000, 0xB70000, 0xB80000, 0xB80000
# define K 0xB90000, 0xB90000, 0xBA0000, 0xBA0000, 0xBB0000, 0xBB0000
# define L 0xBB0000, 0xBC0000, 0xBC0000, 0xBD0000, 0xBD0000, 0xBE0000
# define M 0xBE0000, 0xBE0000, 0xBF0000, 0xBF0000, 0xC00000, 0xC00000
# define N 0xC00000, 0xC10000, 0xC10000, 0xC20000, 0xC20000, 0xC20000
# define O 0xC30000, 0xC30000, 0xC30000, 0xC40000, 0xC40000, 0xC40000
# define P 0xC50000, 0xC50000, 0xC50000, 0xC60000, 0xC60000, 0xC60000
# define Q 0xC70000, 0xC70000, 0xC70000, 0xC80000, 0xC80000, 0xC80000
# define R 0xC90000, 0xC90000, 0xC90000, 0xC90000, 0xCA0000, 0xCA0000
# define S 0xCA0000, 0xCB0000, 0xCB0000, 0xCB0000, 0xCB0000, 0xCC0000
# define T 0xCC0000, 0xCC0000, 0xCC0000, 0xCD0000, 0xCD0000, 0xCD0000
# define U 0xCD0000, 0xCE0000, 0xCE0000, 0xCE0000, 0xCE0000, 0xCE0000
# define V 0xCF0000, 0xCF0000, 0xCF0000, 0xCF0000, 0xCF0000, 0xD00000
# define W 0xD00000, 0xD00000, 0xD00000, 0xD00000, 0xD10000, 0xD10000
# define X 0xD10000, 0xD10000, 0xD10000, 0xD10000, 0xD10000, 0xD20000
# define Y 0xD20000, 0xD20000, 0xD20000, 0xD20000, 0xD20000, 0xD20000
# define Z 0xD30000, 0xD30000, 0xD30000, 0xD30000, 0xD30000, 0xD30000
# define AA A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
# define AB AA, 0xD30000, 0xD30000, 0xD30000, 0xD30000, 0xD40000
# define AC 0xD40000, 0xD40000, 0xD40000, 0xD40000, 0xD40000, 0xD40000
# define AD 0xD40000, 0xD40000, 0xD50000, 0xD50000, 0xD50000, 0xD50000
# define AE 0xD50000, 0xD50000, 0xD50000, 0xD50000, 0xD60000, 0xD60000
# define AF 0xD60000, 0xD60000, 0xD60000, 0xD60000, 0xD60000, 0xD60000
# define AG 0xD60000, 0xD70000, 0xD70000, 0xD70000, 0xD70000, 0xD70000
# define AH 0xD70000, 0xD70000, 0xD70000, 0xD70000, 0xD80000, 0xD80000
# define AI 0xD80000, 0xD80000, 0xD80000, 0xD80000, 0xD80000, 0xD80000
# define AJ 0xD90000, 0xD90000, 0xD90000, 0xD90000, 0xD90000, 0xD90000
# define AK 0xD90000, 0xD90000, 0xD90000, 0xDA0000, 0xDA0000, 0xDA0000
# define AL 0xDA0000, 0xDA0000, 0xDA0000, 0xDA0000, 0xDA0000, 0xDB0000
# define AM 0xDB0000, 0xDB0000, 0xDB0000, 0xDB0000, 0xDB0000, 0xDB0000
# define AN 0xDB0000, 0xDC0000, 0xDC0000, 0xDC0000, 0xDC0000, 0xDC0000
# define AO 0xDC0000, 0xDC0000, 0xDC0000, 0xDD0000, 0xDD0000, 0xDD0000
# define AP 0xDD0000, 0xDD0000, 0xDD0000, 0xDD0000, 0xDD0000, 0xDE0000
# define AQ 0xDE0000, 0xDE0000, 0xDE0000, 0xDE0000, 0xDE0000, 0xDE0000
# define AR 0xDE0000, 0xDF0000, 0xDF0000, 0xDF0000, 0xDF0000, 0xDF0000
# define AS 0xDF0000, 0xDF0000, 0xDF0000, 0xE00000, 0xE00000, 0xE00000
# define AT 0xE00000, 0xE00000, 0xE00000, 0xE00000, 0xE10000, 0xE10000
# define AU 0xE10000, 0xE10000, 0xE10000, 0xE10000, 0xE10000, 0xE10000
# define AV 0xE20000, 0xE20000, 0xE20000, 0xE20000, 0xE20000, 0xE20000
# define AW 0xE20000, 0xE30000, 0xE30000, 0xE30000, 0xE30000, 0xE30000
# define AX 0xE30000, 0xE30000, 0xE30000, 0xE40000, 0xE40000, 0xE40000
# define AY 0xE40000, 0xE40000, 0xE40000, 0xE40000, 0xE50000, 0xE50000
# define AZ 0xE50000, 0xE50000, 0xE50000, 0xE50000, 0xE50000, 0xE60000
# define BA AB,AC,AD,AE,AF,AG,AH,AI,AJ,AK,AL,AM,AN,AO,AP,AQ,AR,AS,AT
# define BB BA,AU,AV,AW,AX,AY,AZ,0xE60000, 0xE60000, 0xE60000, 0xE60000
# define BC 0xE60000, 0xE60000, 0xE60000, 0xE70000, 0xE70000, 0xE70000
# define BD 0xE70000, 0xE70000, 0xE70000, 0xE70000, 0xE80000, 0xE80000
# define BE 0xE80000, 0xE80000, 0xE80000, 0xE80000, 0xE80000, 0xE90000
# define BF 0xE90000, 0xE90000, 0xE90000, 0xE90000, 0xE90000, 0xE90000
# define BG 0xEA0000, 0xEA0000, 0xEA0000, 0xEA0000, 0xEA0000, 0xEA0000
# define BH 0xEA0000, 0xEB0000, 0xEB0000, 0xEB0000, 0xEB0000, 0xEB0000
# define BI 0xEB0000, 0xEC0000, 0xEC0000, 0xEC0000, 0xEC0000, 0xEC0000
# define BJ 0xEC0000, 0xEC0000, 0xED0000, 0xED0000, 0xED0000, 0xED0000
# define BK 0xED0000, 0xED0000, 0xED0000, 0xEE0000, 0xEE0000, 0xEE0000
# define BL 0xEE0000, 0xEE0000, 0xEE0000, 0xEE0000, 0xEF0000, 0xEF0000
# define BM 0xEF0000, 0xEF0000, 0xEF0000, 0xEF0000, 0xF00000, 0xF00000
# define BN 0xF00000, 0xF00000, 0xF00000, 0xF00000, 0xF00000, 0xF10000
# define BO 0xF10000, 0xF10000, 0xF10000, 0xF10000, 0xF10000, 0xF20000
# define BP 0xF20000, 0xF20000, 0xF20000, 0xF20000, 0xF20000, 0xF20000
# define BQ 0xF30000, 0xF30000, 0xF30000, 0xF30000, 0xF30000, 0xF30000
# define BR 0xF40000, 0xF40000, 0xF40000, 0xF40000, 0xF40000, 0xF40000
# define BS 0xF40000, 0xF50000, 0xF50000, 0xF50000, 0xF50000, 0xF50000
# define BT 0xF50000, 0xF60000, 0xF60000, 0xF60000, 0xF60000, 0xF60000
# define BU 0xF60000, 0xF70000, 0xF70000, 0xF70000, 0xF70000, 0xF70000
# define BV 0xF70000, 0xF70000, 0xF80000, 0xF80000, 0xF80000, 0xF80000
# define BW 0xF80000, 0xF80000, 0xF90000, 0xF90000, 0xF90000, 0xF90000
# define BX 0xF90000, 0xF90000, 0xFA0000, 0xFA0000, 0xFA0000, 0xFA0000
# define BY 0xFA0000, 0xFA0000, 0xFB0000, 0xFB0000, 0xFB0000, 0xFB0000
# define BZ 0xFB0000, 0xFB0000, 0xFC0000, 0xFC0000, 0xFC0000, 0xFC0000
# define CA BB,BC,BD,BE,BF,BG,BH,BI,BJ,BK,BL,BM,BN,BO,BP,BQ,BR,BS,BT
# define CB CA,BU,BV,BW,BX,BY,BZ,0xFC0000, 0xFC0000, 0xFD0000, 0xFD0000
# define CC 0xFD0000, 0xFD0000, 0xFD0000, 0xFD0000, 0xFE0000, 0xFE0000
# define CD 0xFE0000, 0xFE0000, 0xFE0000, 0xFE0000, 0xFF0000, 0xFF0000
# define CE 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CF 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CG 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CH 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CI 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CJ 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CK 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CL 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CM 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CN 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000
# define CO 0xFF0000, 0xFF0000, 0xFF0100, 0xFF0200, 0xFF0400, 0xFF0500
# define CP 0xFF0700, 0xFF0900, 0xFF0A00, 0xFF0C00, 0xFF0D00, 0xFF0E00
# define CQ 0xFF1000, 0xFF1100, 0xFF1200, 0xFF1300, 0xFF1400, 0xFF1500
# define CR 0xFF1600, 0xFF1700, 0xFF1800, 0xFF1900, 0xFF1A00, 0xFF1A00
# define CS 0xFF1B00, 0xFF1C00, 0xFF1D00, 0xFF1D00, 0xFF1E00, 0xFF1F00
# define CT 0xFF2000, 0xFF2000, 0xFF2100, 0xFF2200, 0xFF2200, 0xFF2300
# define CU 0xFF2400, 0xFF2400, 0xFF2500, 0xFF2600, 0xFF2600, 0xFF2700
# define CV 0xFF2700, 0xFF2800, 0xFF2900, 0xFF2900, 0xFF2A00, 0xFF2A00
# define CW 0xFF2B00, 0xFF2C00, 0xFF2C00, 0xFF2D00, 0xFF2D00, 0xFF2E00
# define CX 0xFF2E00, 0xFF2F00, 0xFF2F00, 0xFF3000, 0xFF3000, 0xFF3100
# define CY 0xFF3100, 0xFF3200, 0xFF3200, 0xFF3300, 0xFF3300, 0xFF3400
# define CZ 0xFF3400, 0xFF3500, 0xFF3500, 0xFF3600, 0xFF3600, 0xFF3700
# define DA CB,CC,CD,CE,CF,CG,CH,CI,CJ,CK,CL,CM,CN,CO,CP,CQ,CR,CS,CT
# define DB DA,CU,CV,CW,CX,CY,CZ,0xFF3700, 0xFF3800, 0xFF3800, 0xFF3900
# define DC 0xFF3900, 0xFF3A00, 0xFF3A00, 0xFF3B00, 0xFF3B00, 0xFF3B00
# define DD 0xFF3C00, 0xFF3C00, 0xFF3D00, 0xFF3D00, 0xFF3E00, 0xFF3E00
# define DE 0xFF3F00, 0xFF3F00, 0xFF3F00, 0xFF4000, 0xFF4000, 0xFF4100
# define DF 0xFF4100, 0xFF4200, 0xFF4200, 0xFF4300, 0xFF4300, 0xFF4300
# define DG 0xFF4400, 0xFF4400, 0xFF4500, 0xFF4500, 0xFF4500, 0xFF4600
# define DH 0xFF4600, 0xFF4700, 0xFF4700, 0xFF4800, 0xFF4800, 0xFF4800
# define DI 0xFF4900, 0xFF4900, 0xFF4A00, 0xFF4A00, 0xFF4A00, 0xFF4B00
# define DJ 0xFF4B00, 0xFF4C00, 0xFF4C00, 0xFF4C00, 0xFF4D00, 0xFF4D00
# define DK 0xFF4E00, 0xFF4E00, 0xFF4E00, 0xFF4F00, 0xFF4F00, 0xFF5000
# define DL 0xFF5000, 0xFF5000, 0xFF5100, 0xFF5100, 0xFF5200, 0xFF5200
# define DM 0xFF5200, 0xFF5300, 0xFF5300, 0xFF5300, 0xFF5400, 0xFF5400
# define DN 0xFF5500, 0xFF5500, 0xFF5500, 0xFF5600, 0xFF5600, 0xFF5700
# define DO 0xFF5700, 0xFF5700, 0xFF5800, 0xFF5800, 0xFF5800, 0xFF5900
# define DP 0xFF5900, 0xFF5A00, 0xFF5A00, 0xFF5A00, 0xFF5B00, 0xFF5B00
# define DQ 0xFF5C00, 0xFF5C00, 0xFF5C00, 0xFF5D00, 0xFF5D00, 0xFF5D00
# define DR 0xFF5E00, 0xFF5E00, 0xFF5F00, 0xFF5F00, 0xFF5F00, 0xFF6000
# define DS 0xFF6000, 0xFF6000, 0xFF6100, 0xFF6100, 0xFF6100, 0xFF6200
# define DT 0xFF6200, 0xFF6300, 0xFF6300, 0xFF6300, 0xFF6400, 0xFF6400
# define DU 0xFF6400, 0xFF6500, 0xFF6500, 0xFF6600, 0xFF6600, 0xFF6600
# define DV 0xFF6700, 0xFF6700, 0xFF6700, 0xFF6800, 0xFF6800, 0xFF6800
# define DW 0xFF6900, 0xFF6900, 0xFF6A00, 0xFF6A00, 0xFF6A00, 0xFF6B00
# define DX 0xFF6B00, 0xFF6B00, 0xFF6C00, 0xFF6C00, 0xFF6D00, 0xFF6D00
# define DY 0xFF6D00, 0xFF6E00, 0xFF6E00, 0xFF6E00, 0xFF6F00, 0xFF6F00
# define DZ 0xFF6F00, 0xFF7000, 0xFF7000, 0xFF7100, 0xFF7100, 0xFF7100
# define EA DB,DC,DD,DE,DF,DG,DH,DI,DJ,DK,DL,DM,DN,DO,DP,DQ,DR,DS,DT
# define EB EA,DU,DV,DW,DX,DY,DZ,0xFF7200, 0xFF7200, 0xFF7200, 0xFF7300
# define EC 0xFF7300, 0xFF7300, 0xFF7400, 0xFF7400, 0xFF7400, 0xFF7500
# define ED 0xFF7500, 0xFF7600, 0xFF7600, 0xFF7600, 0xFF7700, 0xFF7700
# define EE 0xFF7700, 0xFF7800, 0xFF7800, 0xFF7800, 0xFF7900, 0xFF7900
# define EF 0xFF7A00, 0xFF7A00, 0xFF7A00, 0xFF7B00, 0xFF7B00, 0xFF7B00
# define EG 0xFF7C00, 0xFF7C00, 0xFF7C00, 0xFF7D00, 0xFF7D00, 0xFF7E00
# define EH 0xFF7E00, 0xFF7E00, 0xFF7F00, 0xFF7F00, 0xFF7F00, 0xFF8000
# define EI 0xFF8000, 0xFF8000, 0xFF8100, 0xFF8100, 0xFF8200, 0xFF8200
# define EJ 0xFF8200, 0xFF8300, 0xFF8300, 0xFF8300, 0xFF8400, 0xFF8400
# define EK 0xFF8400, 0xFF8500, 0xFF8500, 0xFF8600, 0xFF8600, 0xFF8600
# define EL 0xFF8700, 0xFF8700, 0xFF8700, 0xFF8800, 0xFF8800, 0xFF8800
# define EM 0xFF8900, 0xFF8900, 0xFF8900, 0xFF8A00, 0xFF8A00, 0xFF8B00
# define EN 0xFF8B00, 0xFF8B00, 0xFF8C00, 0xFF8C00, 0xFF8C00, 0xFF8D00
# define EO 0xFF8D00, 0xFF8D00, 0xFF8E00, 0xFF8E00, 0xFF8F00, 0xFF8F00
# define EP 0xFF8F00, 0xFF9000, 0xFF9000, 0xFF9000, 0xFF9100, 0xFF9100
# define EQ 0xFF9200, 0xFF9200, 0xFF9200, 0xFF9300, 0xFF9300, 0xFF9300
# define ER 0xFF9400, 0xFF9400, 0xFF9400, 0xFF9500, 0xFF9500, 0xFF9600
# define ES 0xFF9600, 0xFF9600, 0xFF9700, 0xFF9700, 0xFF9700, 0xFF9800
# define ET 0xFF9800, 0xFF9800, 0xFF9900, 0xFF9900, 0xFF9A00, 0xFF9A00
# define EU 0xFF9A00, 0xFF9B00, 0xFF9B00, 0xFF9B00, 0xFF9C00, 0xFF9C00
# define EV 0xFF9D00, 0xFF9D00, 0xFF9D00, 0xFF9E00, 0xFF9E00, 0xFF9E00
# define EW 0xFF9F00, 0xFF9F00, 0xFF9F00, 0xFFA000, 0xFFA000, 0xFFA100
# define EX 0xFFA100, 0xFFA100, 0xFFA200, 0xFFA200, 0xFFA200, 0xFFA300
# define EY 0xFFA300, 0xFFA400, 0xFFA400, 0xFFA400, 0xFFA500, 0xFFA500
# define EZ 0xFFA500, 0xFFA600, 0xFFA600, 0xFFA700, 0xFFA700, 0xFFA700
# define FA EB,EC,ED,EE,EF,EG,EH,EI,EJ,EK,EL,EM,EN,EO,EP,EQ,ER,ES,ET
# define FB FA,EU,EV,EW,EX,EY,EZ,0xFFA800, 0xFFA800, 0xFFA800, 0xFFA900
# define FC 0xFFA900, 0xFFAA00, 0xFFAA00, 0xFFAA00, 0xFFAB00, 0xFFAB00
# define FD 0xFFAB00, 0xFFAC00, 0xFFAC00, 0xFFAD00, 0xFFAD00, 0xFFAD00
# define FE 0xFFAE00, 0xFFAE00, 0xFFAE00, 0xFFAF00, 0xFFAF00, 0xFFB000
# define FF 0xFFB000, 0xFFB000, 0xFFB100, 0xFFB100, 0xFFB100, 0xFFB200
# define FG 0xFFB200, 0xFFB300, 0xFFB300, 0xFFB300, 0xFFB400, 0xFFB400
# define FH 0xFFB400, 0xFFB500, 0xFFB500, 0xFFB600, 0xFFB600, 0xFFB600
# define FI 0xFFB700, 0xFFB700, 0xFFB800, 0xFFB800, 0xFFB800, 0xFFB900
# define FJ 0xFFB900, 0xFFB900, 0xFFBA00, 0xFFBA00, 0xFFBB00, 0xFFBB00
# define FK 0xFFBB00, 0xFFBC00, 0xFFBC00, 0xFFBD00, 0xFFBD00, 0xFFBD00
# define FL 0xFFBE00, 0xFFBE00, 0xFFBE00, 0xFFBF00, 0xFFBF00, 0xFFC000
# define FM 0xFFC000, 0xFFC000, 0xFFC100, 0xFFC100, 0xFFC200, 0xFFC200
# define FN 0xFFC200, 0xFFC300, 0xFFC300, 0xFFC400, 0xFFC400, 0xFFC400
# define FO 0xFFC500, 0xFFC500, 0xFFC500, 0xFFC600, 0xFFC600, 0xFFC700
# define FP 0xFFC700, 0xFFC700, 0xFFC800, 0xFFC800, 0xFFC900, 0xFFC900
# define FQ 0xFFC900, 0xFFCA00, 0xFFCA00, 0xFFCB00, 0xFFCB00, 0xFFCB00
# define FR 0xFFCC00, 0xFFCC00, 0xFFCD00, 0xFFCD00, 0xFFCD00, 0xFFCE00
# define FS 0xFFCE00, 0xFFCF00, 0xFFCF00
# define FIRE FB,FC,FD,FE,FF,FG,FH,FI,FJ,FK,FL,FM,FN,FO,FP,FQ,FR,FS

#endif