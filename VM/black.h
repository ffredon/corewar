/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 21:23:37 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/21 00:03:53 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLACK_H
# define BLACK_H

# define A 0x000000, 0x000000, 0x010101, 0x010101, 0x010201, 0x020202
# define B 0x020202, 0x030303, 0x030303, 0x030303, 0x040404, 0x040404
# define C 0x040404, 0x050505, 0x050505, 0x060506, 0x060606, 0x060606
# define D 0x070707, 0x070707, 0x070707, 0x080808, 0x080808, 0x080808
# define E 0x090909, 0x090909, 0x0A0A0A, 0x0A0A0A, 0x0A0A0A, 0x0B0B0B
# define F 0x0B0B0B, 0x0B0B0B, 0x0C0C0C, 0x0C0C0C, 0x0C0C0C, 0x0D0D0D
# define G 0x0D0D0D, 0x0D0D0D, 0x0E0E0E, 0x0E0E0E, 0x0E0E0E, 0x0F0E0E
# define H 0x0F0F0F, 0x0F0F0F, 0x0F0F0F, 0x101010, 0x101010, 0x101010
# define I 0x101010, 0x111111, 0x111111, 0x111111, 0x111111, 0x121212
# define J 0x121212, 0x121212, 0x121212, 0x131313, 0x131313, 0x131313
# define K 0x131313, 0x141414, 0x141414, 0x141414, 0x141414, 0x141515
# define L 0x151515, 0x151515, 0x151515, 0x151515, 0x161616, 0x161616
# define M 0x161616, 0x161616, 0x161616, 0x171717, 0x171717, 0x171717
# define N 0x171717, 0x171717, 0x181818, 0x181818, 0x181818, 0x181818
# define O 0x181818, 0x191919, 0x191919, 0x191919, 0x191919, 0x191919
# define P 0x1A1A1A, 0x1A1A1A, 0x1A1A1A, 0x1A1A1A, 0x1A1A1A, 0x1B1B1B
# define Q 0x1B1B1B, 0x1B1B1B, 0x1B1B1B, 0x1B1B1B, 0x1C1C1C, 0x1C1C1C
# define R 0x1C1C1C, 0x1C1C1C, 0x1C1C1C, 0x1D1D1D, 0x1D1D1D, 0x1D1D1D
# define S 0x1D1D1D, 0x1D1D1D, 0x1E1E1E, 0x1E1E1E, 0x1E1E1E, 0x1E1E1E
# define T 0x1E1E1E, 0x1F1F1F, 0x1F1F1F, 0x1F1F1F, 0x1F1F1F, 0x1F1F1F
# define U 0x202020, 0x202020, 0x202020, 0x202020, 0x212020, 0x212121
# define V 0x212121, 0x212121, 0x212121, 0x222222, 0x222222, 0x222222
# define W 0x222222, 0x222222, 0x232323, 0x232323, 0x232323, 0x232323
# define X 0x232323, 0x242424, 0x242424, 0x242424, 0x242424, 0x242424
# define Y 0x252525, 0x252525, 0x252525, 0x252525, 0x252525, 0x262626
# define Z 0x262626, 0x262626, 0x262626, 0x272727, 0x272727, 0x272727
# define AA A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z
# define AB AA, 0x272727, 0x272727, 0x282828, 0x282828, 0x282828
# define AC 0x282828, 0x282828, 0x292929, 0x292929, 0x292929, 0x292929
# define AD 0x2A2A2A, 0x2A2A2A, 0x2A2A2A, 0x2A2A2A, 0x2A2A2A, 0x2B2B2B
# define AE 0x2B2B2B, 0x2B2B2B, 0x2B2B2B, 0x2B2B2B, 0x2C2C2C, 0x2C2C2C
# define AF 0x2C2C2C, 0x2C2C2C, 0x2C2D2C, 0x2D2D2D, 0x2D2D2D, 0x2D2D2D
# define AG 0x2D2D2D, 0x2E2E2E, 0x2E2E2E, 0x2E2E2E, 0x2E2E2E, 0x2E2E2E
# define AH 0x2F2F2F, 0x2F2F2F, 0x2F2F2F, 0x2F2F2F, 0x303030, 0x303030
# define AI 0x303030, 0x303030, 0x303030, 0x313131, 0x313131, 0x313131
# define AJ 0x313131, 0x313231, 0x323232, 0x323232, 0x323232, 0x323232
# define AK 0x333333, 0x333333, 0x333333, 0x333333, 0x333333, 0x343434
# define AL 0x343434, 0x343434, 0x343434, 0x353535, 0x353535, 0x353535
# define AM 0x353535, 0x353535, 0x363636, 0x363636, 0x363636, 0x363636
# define AN 0x373737, 0x373737, 0x373737, 0x373737, 0x373737, 0x383838
# define AO 0x383838, 0x383838, 0x383838, 0x393939, 0x393939, 0x393939
# define AP 0x393939, 0x393939, 0x3A3A3A, 0x3A3A3A, 0x3A3A3A, 0x3A3A3A
# define AQ 0x3B3B3B, 0x3B3B3B, 0x3B3B3B, 0x3B3B3B, 0x3B3C3B, 0x3C3C3C
# define AR 0x3C3C3C, 0x3C3C3C, 0x3C3C3C, 0x3D3D3D, 0x3D3D3D, 0x3D3D3D
# define AS 0x3D3D3D, 0x3E3E3E, 0x3E3E3E, 0x3E3E3E, 0x3E3E3E, 0x3E3E3E
# define AT 0x3F3F3F, 0x3F3F3F, 0x3F3F3F, 0x3F3F3F, 0x404040, 0x404040
# define AU 0x404040, 0x404040, 0x404040, 0x414141, 0x414141, 0x414141
# define AV 0x414141, 0x424242, 0x424242, 0x424242, 0x424242, 0x434343
# define AW 0x434343, 0x434343, 0x434343, 0x434343, 0x444444, 0x444444
# define AX 0x444444, 0x444444, 0x454545, 0x454545, 0x454545, 0x454545
# define AY 0x464646, 0x464646, 0x464646, 0x464646, 0x464646, 0x474747
# define AZ 0x474747, 0x474747, 0x474747, 0x484848, 0x484848, 0x484848
# define BA AB,AC,AD,AE,AF,AG,AH,AI,AJ,AK,AL,AM,AN,AO,AP,AQ,AR,AS,AT
# define BB BA,AU,AV,AW,AX,AY,AZ,0x484848, 0x494949, 0x494949, 0x494949
# define BC 0x494949, 0x4A4949, 0x4A4A4A, 0x4A4A4A, 0x4A4A4A, 0x4A4A4A
# define BD 0x4B4B4B, 0x4B4B4B, 0x4B4B4B, 0x4B4B4B, 0x4C4C4C, 0x4C4C4C
# define BE 0x4C4C4C, 0x4C4C4C, 0x4D4D4D, 0x4D4D4D, 0x4D4D4D, 0x4D4D4D
# define BF 0x4D4D4D, 0x4E4E4E, 0x4E4E4E, 0x4E4E4E, 0x4E4E4E, 0x4F4F4F
# define BG 0x4F4F4F, 0x4F4F4F, 0x4F4F4F, 0x505050, 0x505050, 0x505050
# define BH 0x505050, 0x515151, 0x515151, 0x515151, 0x515151, 0x515251
# define BI 0x525252, 0x525252, 0x525252, 0x525252, 0x535353, 0x535353
# define BJ 0x535353, 0x535353, 0x545454, 0x545454, 0x545454, 0x545454
# define BK 0x555555, 0x555555, 0x555555, 0x555555, 0x565656, 0x565656
# define BL 0x565656, 0x565656, 0x575757, 0x575757, 0x575757, 0x575757
# define BM 0x575757, 0x585858, 0x585858, 0x585858, 0x585858, 0x595959
# define BN 0x595959, 0x595959, 0x595959, 0x5A5A5A, 0x5A5A5A, 0x5A5A5A
# define BO 0x5A5A5A, 0x5B5B5B, 0x5B5B5B, 0x5B5B5B, 0x5B5B5B, 0x5C5C5C
# define BP 0x5C5C5C, 0x5C5C5C, 0x5C5C5C, 0x5D5D5D, 0x5D5D5D, 0x5D5D5D
# define BQ 0x5D5D5D, 0x5E5E5E, 0x5E5E5E, 0x5E5E5E, 0x5E5E5E, 0x5E5F5E
# define BR 0x5F5F5F, 0x5F5F5F, 0x5F5F5F, 0x5F5F5F, 0x606060, 0x606060
# define BS 0x606060, 0x606060, 0x616161, 0x616161, 0x616161, 0x616161
# define BT 0x626262, 0x626262, 0x626262, 0x626262, 0x636363, 0x636363
# define BU 0x636363, 0x636363, 0x646464, 0x646464, 0x646464, 0x646464
# define BV 0x656565, 0x656565, 0x656565, 0x656565, 0x666666, 0x666666
# define BW 0x666666, 0x666666, 0x676767, 0x676767, 0x676767, 0x676767
# define BX 0x686868, 0x686868, 0x686868, 0x686868, 0x696969, 0x696969
# define BY 0x696969, 0x696969, 0x6A6A6A, 0x6A6A6A, 0x6A6A6A, 0x6A6A6A
# define BZ 0x6B6B6B, 0x6B6B6B, 0x6B6B6B, 0x6B6B6B, 0x6C6C6C, 0x6C6C6C
# define CA BB,BC,BD,BE,BF,BG,BH,BI,BJ,BK,BL,BM,BN,BO,BP,BQ,BR,BS,BT
# define CB CA,BU,BV,BW,BX,BY,BZ,0x6C6C6C, 0x6C6C6C, 0x6D6D6D, 0x6D6D6D
# define CC 0x6D6D6D, 0x6D6D6D, 0x6E6E6E, 0x6E6E6E, 0x6E6E6E, 0x6E6E6E
# define CD 0x6F6F6F, 0x6F6F6F, 0x6F6F6F, 0x6F6F6F, 0x707070, 0x707070
# define CE 0x707070, 0x707070, 0x717171, 0x717171, 0x717171, 0x717171
# define CF 0x727272, 0x727272, 0x727272, 0x727272, 0x737373, 0x737373
# define CG 0x737373, 0x737373, 0x747474, 0x747474, 0x747474, 0x747474
# define CH 0x757575, 0x757575, 0x757575, 0x757575, 0x767676, 0x767676
# define CI 0x767676, 0x767676, 0x777777, 0x777777, 0x777777, 0x777777
# define CJ 0x787878, 0x787878, 0x787878, 0x787878, 0x797979, 0x797979
# define CK 0x797979, 0x797979, 0x7A7A7A, 0x7A7A7A, 0x7A7A7A, 0x7A7A7A
# define CL 0x7B7B7B, 0x7B7B7B, 0x7B7B7B, 0x7B7B7B, 0x7C7C7C, 0x7C7C7C
# define CM 0x7C7C7C, 0x7C7C7C, 0x7D7D7D, 0x7D7D7D, 0x7D7D7D, 0x7E7E7D
# define CN 0x7E7E7E, 0x7E7E7E, 0x7E7E7E, 0x7F7F7F, 0x7F7F7F, 0x7F7F7F
# define CO 0x7F7F7F, 0x808080, 0x808080, 0x808080, 0x808080, 0x818181
# define CP 0x818181, 0x818181, 0x818181, 0x828282, 0x828282, 0x828282
# define CQ 0x828282, 0x838383, 0x838383, 0x838383, 0x838383, 0x848484
# define CR 0x848484, 0x848484, 0x848484, 0x858585, 0x858585, 0x858585
# define CS 0x858585, 0x868686, 0x868686, 0x868686, 0x878787, 0x878787
# define CT 0x878787, 0x878787, 0x888888, 0x888888, 0x888888, 0x888888
# define CU 0x898989, 0x898989, 0x898989, 0x898989, 0x8A8A8A, 0x8A8A8A
# define CV 0x8A8A8A, 0x8A8A8A, 0x8B8B8B, 0x8B8B8B, 0x8B8B8B, 0x8B8B8B
# define CW 0x8C8C8C, 0x8C8C8C, 0x8C8C8C, 0x8D8D8D, 0x8D8D8D, 0x8D8D8D
# define CX 0x8D8D8D, 0x8E8E8E, 0x8E8E8E, 0x8E8E8E, 0x8E8E8E, 0x8F8F8F
# define CY 0x8F8F8F, 0x8F8F8F, 0x8F8F8F, 0x909090, 0x909090, 0x909090
# define CZ 0x909090, 0x919191, 0x919191, 0x919191, 0x929291, 0x929292
# define DA CB,CC,CD,CE,CF,CG,CH,CI,CJ,CK,CL,CM,CN,CO,CP,CQ,CR,CS,CT
# define DB DA,CU,CV,CW,CX,CY,CZ,0x929292, 0x929292, 0x939393, 0x939393
# define DC 0x939393, 0x939393, 0x949494, 0x949494, 0x949494, 0x949494
# define DD 0x959595, 0x959595, 0x959595, 0x959595, 0x969696, 0x969696
# define DE 0x969696, 0x979797, 0x979797, 0x979797, 0x979797, 0x989898
# define DF 0x989898, 0x989898, 0x989898, 0x999999, 0x999999, 0x999999
# define DG 0x999999, 0x9A9A9A, 0x9A9A9A, 0x9A9A9A, 0x9A9B9A, 0x9B9B9B
# define DH 0x9B9B9B, 0x9B9B9B, 0x9C9C9C, 0x9C9C9C, 0x9C9C9C, 0x9C9C9C
# define DI 0x9D9D9D, 0x9D9D9D, 0x9D9D9D, 0x9D9D9D, 0x9E9E9E, 0x9E9E9E
# define DJ 0x9E9E9E, 0x9F9F9E, 0x9F9F9F, 0x9F9F9F, 0x9F9F9F, 0xA0A0A0
# define DK 0xA0A0A0, 0xA0A0A0, 0xA0A0A0, 0xA1A1A1, 0xA1A1A1, 0xA1A1A1
# define DL 0xA1A1A1, 0xA2A2A2, 0xA2A2A2, 0xA2A2A2, 0xA3A3A3, 0xA3A3A3
# define DM 0xA3A3A3, 0xA3A3A3, 0xA4A4A4, 0xA4A4A4, 0xA4A4A4, 0xA4A4A4
# define DN 0xA5A5A5, 0xA5A5A5, 0xA5A5A5, 0xA5A5A5, 0xA6A6A6, 0xA6A6A6
# define DO 0xA6A6A6, 0xA7A7A7, 0xA7A7A7, 0xA7A7A7, 0xA7A7A7, 0xA8A8A8
# define DP 0xA8A8A8, 0xA8A8A8, 0xA8A8A8, 0xA9A9A9, 0xA9A9A9, 0xA9A9A9
# define DQ 0xAAAAAA, 0xAAAAAA, 0xAAAAAA, 0xAAAAAA, 0xABABAB, 0xABABAB
# define DR 0xABABAB, 0xABABAB, 0xACACAC, 0xACACAC, 0xACACAC, 0xADADAC
# define DS 0xADADAD, 0xADADAD, 0xADADAD, 0xAEAEAE, 0xAEAEAE, 0xAEAEAE
# define DT 0xAEAEAE, 0xAFAFAF, 0xAFAFAF, 0xAFAFAF, 0xAFB0AF, 0xB0B0B0
# define DU 0xB0B0B0, 0xB0B0B0, 0xB1B1B1, 0xB1B1B1, 0xB1B1B1, 0xB1B1B1
# define DV 0xB2B2B2, 0xB2B2B2, 0xB2B2B2, 0xB3B3B2, 0xB3B3B3, 0xB3B3B3
# define DW 0xB3B3B3, 0xB4B4B4, 0xB4B4B4, 0xB4B4B4, 0xB4B4B4, 0xB5B5B5
# define DX 0xB5B5B5, 0xB5B5B5, 0xB6B6B5, 0xB6B6B6, 0xB6B6B6, 0xB6B6B6
# define DY 0xB7B7B7, 0xB7B7B7, 0xB7B7B7, 0xB7B7B7, 0xB8B8B8, 0xB8B8B8
# define DZ 0xB8B8B8, 0xB9B9B9, 0xB9B9B9, 0xB9B9B9, 0xB9B9B9, 0xBABABA
# define EA DB,DC,DD,DE,DF,DG,DH,DI,DJ,DK,DL,DM,DN,DO,DP,DQ,DR,DS,DT
# define EB EA,DU,DV,DW,DX,DY,DZ,0xBABABA, 0xBABABA, 0xBABABA, 0xBBBBBB
# define EC 0xBBBBBB, 0xBBBBBB, 0xBCBCBC, 0xBCBCBC, 0xBCBCBC, 0xBCBCBC
# define ED 0xBDBDBD, 0xBDBDBD, 0xBDBDBD, 0xBDBEBD, 0xBEBEBE, 0xBEBEBE
# define EE 0xBEBEBE, 0xBFBFBF, 0xBFBFBF, 0xBFBFBF, 0xBFBFBF, 0xC0C0C0
# define EF 0xC0C0C0, 0xC0C0C0, 0xC1C1C1, 0xC1C1C1, 0xC1C1C1, 0xC1C1C1
# define EG 0xC2C2C2, 0xC2C2C2, 0xC2C2C2, 0xC2C2C2, 0xC3C3C3, 0xC3C3C3
# define EH 0xC3C3C3, 0xC4C4C4, 0xC4C4C4, 0xC4C4C4, 0xC4C4C4, 0xC5C5C5
# define EI 0xC5C5C5, 0xC5C5C5, 0xC6C6C6, 0xC6C6C6, 0xC6C6C6, 0xC6C6C6
# define EJ 0xC7C7C7, 0xC7C7C7, 0xC7C7C7, 0xC7C7C7, 0xC8C8C8, 0xC8C8C8
# define EK 0xC8C8C8, 0xC9C9C9, 0xC9C9C9, 0xC9C9C9, 0xC9C9C9, 0xCACACA
# define EL 0xCACACA, 0xCACACA, 0xCBCBCB, 0xCBCBCB, 0xCBCBCB, 0xCBCBCB
# define EM 0xCCCCCC, 0xCCCCCC, 0xCCCCCC, 0xCDCDCD, 0xCDCDCD, 0xCDCDCD
# define EN 0xCDCDCD, 0xCECECE, 0xCECECE, 0xCECECE, 0xCECECE, 0xCFCFCF
# define EO 0xCFCFCF, 0xCFCFCF, 0xD0D0D0, 0xD0D0D0, 0xD0D0D0, 0xD0D0D0
# define EP 0xD1D1D1, 0xD1D1D1, 0xD1D1D1, 0xD2D2D2, 0xD2D2D2, 0xD2D2D2
# define EQ 0xD2D2D2, 0xD3D3D3, 0xD3D3D3, 0xD3D3D3, 0xD4D4D4, 0xD4D4D4
# define ER 0xD4D4D4, 0xD4D4D4, 0xD5D5D5, 0xD5D5D5, 0xD5D5D5, 0xD6D6D6
# define ES 0xD6D6D6, 0xD6D6D6, 0xD6D6D6, 0xD7D7D7, 0xD7D7D7, 0xD7D7D7
# define ET 0xD8D8D7, 0xD8D8D8, 0xD8D8D8, 0xD8D8D8, 0xD9D9D9, 0xD9D9D9
# define EU 0xD9D9D9, 0xD9D9D9, 0xDADADA, 0xDADADA, 0xDADADA, 0xDBDBDB
# define EV 0xDBDBDB, 0xDBDBDB, 0xDBDBDB, 0xDCDCDC, 0xDCDCDC, 0xDCDCDC
# define EW 0xDDDDDD, 0xDDDDDD, 0xDDDDDD, 0xDDDDDD, 0xDEDEDE, 0xDEDEDE
# define EX 0xDEDEDE, 0xDFDFDF, 0xDFDFDF, 0xDFDFDF, 0xDFDFDF, 0xE0E0E0
# define EY 0xE0E0E0, 0xE0E0E0, 0xE1E1E1, 0xE1E1E1, 0xE1E1E1, 0xE1E1E1
# define EZ 0xE2E2E2, 0xE2E2E2, 0xE2E2E2, 0xE3E3E3, 0xE3E3E3, 0xE3E3E3
# define FA EB,EC,ED,EE,EF,EG,EH,EI,EJ,EK,EL,EM,EN,EO,EP,EQ,ER,ES,ET
# define FB FA,EU,EV,EW,EX,EY,EZ,0xE3E3E3, 0xE4E4E4, 0xE4E4E4, 0xE4E4E4
# define FC 0xE5E5E5, 0xE5E5E5, 0xE5E5E5, 0xE5E5E5, 0xE6E6E6, 0xE6E6E6
# define FD 0xE6E6E6, 0xE7E7E7, 0xE7E7E7, 0xE7E7E7, 0xE7E7E7, 0xE8E8E8
# define FE 0xE8E8E8, 0xE8E8E8, 0xE9E9E9, 0xE9E9E9, 0xE9E9E9, 0xE9E9E9
# define FF 0xEAEAEA, 0xEAEAEA, 0xEAEAEA, 0xEBEBEB, 0xEBEBEB, 0xEBEBEB
# define FG 0xEBEBEB, 0xECECEC, 0xECECEC, 0xECECEC, 0xEDEDED, 0xEDEDED
# define FH 0xEDEDED, 0xEEEEED, 0xEEEEEE, 0xEEEEEE, 0xEEEEEE, 0xEFEFEF
# define FI 0xEFEFEF, 0xEFEFEF, 0xF0F0EF, 0xF0F0F0, 0xF0F0F0, 0xF0F0F0
# define FJ 0xF1F1F1, 0xF1F1F1, 0xF1F1F1, 0xF2F2F2, 0xF2F2F2, 0xF2F2F2
# define FK 0xF2F2F2, 0xF3F3F3, 0xF3F3F3, 0xF3F3F3, 0xF4F4F4, 0xF4F4F4
# define FL 0xF4F4F4, 0xF4F4F4, 0xF5F5F5, 0xF5F5F5, 0xF5F5F5, 0xF6F6F6
# define FM 0xF6F6F6, 0xF6F6F6, 0xF6F6F6, 0xF7F7F7, 0xF7F7F7, 0xF7F7F7
# define FN 0xF8F8F8, 0xF8F8F8, 0xF8F8F8, 0xF8F9F8, 0xF9F9F9, 0xF9F9F9
# define FO 0xF9F9F9, 0xFAFAFA, 0xFAFAFA, 0xFAFAFA, 0xFBFBFB, 0xFBFBFB
# define FP 0xFBFBFB, 0xFBFBFB, 0xFCFCFC, 0xFCFCFC, 0xFCFCFC, 0xFDFDFD
# define FQ 0xFDFDFD, 0xFDFDFD, 0xFDFDFD, 0xFEFEFE, 0xFEFEFE, 0xFEFEFE
# define FR 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF
# define FS 0xFFFFFF, 0xFFFFFF, 0xFFFFFF
# define BLACK FB,FC,FD,FE,FF,FG,FH,FI,FJ,FK,FL,FM,FN,FO,FP,FQ,FR,FS

#endif
