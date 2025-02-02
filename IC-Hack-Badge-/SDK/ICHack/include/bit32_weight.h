
#ifndef BIT32_WEIGHT_H
#define BIT32_WEIGHT_H

#include <cstring>
#include "config.h"

static const int32_t weights_1[WEIGHT_1_ROWS][WEIGHT_1_COLS] = {
        { 18077,  -1843, -14486,  22944,   5687,  -2848, -19453,  10433,   1924,
           -599, -10616, -21269,   8233,  24282,  -3604,  -2868,  -2556,   6157,
          31532, -30754,   -171,   8447,  -9385,  21277,   3150,   -586, -43021,
           2330, -21509,  10395,  38636,  17797,   3191,    887, -11493,   8699,
         -14691,   9782,  -8306,  19791,  27727,   -221,   3478,  15898, -17080,
           9367,  29626,   8726,   2885,  15902,  -6088,   1740,  34147, -38089,
          45465,   6167,  34465,   7863,   4677, -32267, -18641,  -6694,  13089,
          -6146, -23517,   8451,  22404, -27144,   7644, -14654,  25186,  10945,
           5545,   9664,   7045, -28505,   8339, -24254,    592,  15952, -25699,
         -46920,  -2993,  21522,   2970,   9382, -16216,   1140,  -5840,  11142,
         -23553,  -5438,  -5552,  33259,   2417,   3652, -13323,  26764,   2679,
          -2846,  21418, -10090, -27610, -19744,  10528, -11215,  -9729,  -8574,
         -15925,   9839,  -4853,  -6713,    276, -11585,  32581,  -7128,  33269,
          -6371, -25538,   2467,  -5030, -20718,   3197,  14379,   4108,  19290,
            166, -16104,  -3932,    567,  20372,  -6466,  -3470, -10611,  18264,
         -24527,  -8536,   9666,   5521,   8624,  38524, -43202,  -6011,  44286,
          14774,  -4755, -11888,   4724,  13526,    219,  20072, -25227, -12047,
           6792,  36743, -15965,  -2758,  14467,  13655,  11622,   8838,  33973,
          17058,  10394,   4613,  -9084,  34462,   9480,  -8992,   1077, -16847,
         -12145,  14104, -16024,  -4503, -12018,  20903,  38717, -25504,  14007,
          -5223,  12481,  -6279,  -3273,  10379, -18732, -43604, -14061,  31386,
          -8501,   5027,  16976,  14608,   9785,  43229, -24791, -19067,   4168,
          13809, -21098,  19038, -13925, -25667,  -8867, -16919,   8339,  13677,
           5138, -17671,  20499,   3663, -16932,  17728,  37058,  -3496,  12271,
          -8596, -13675,  -3778,  35186,  -7127,  42513,  -1883, -27139, -18514,
         -10181, -10242,   8354, -14290, -29916, -11681,   2022, -31085,  13489,
          -7789,   2653,  28293,  23406, -36770, -17049,  12998,  34332, -16451,
          27755, -19685,  -2096,   9584,  -9908,  34850,  26069, -12715,   5962,
         -39511,  -9749,   4926,   6878},
        {   646,  -6540, -31617,  -2890,   -635,   7736,  17452, -32578,  31651,
          21614,  48203,  21430,  20446,  19666,   2177,  39264,  45674, -16683,
         -26809,  33782,   8867, -45976,  21060,   9424,   1934,   3540,  26388,
         -31623,  -1483,  -4823, -29009,  14441,   4217, -23754,  -8043,  37241,
         -39470, -11223,  -3787, -25847,  -2263, -12951,  24698, -21435,  28616,
           8770, -26395,  24447,  45810, -12243,  -3869, -57037, -45448,  -1659,
           3798, -57752,   -147,  -2534,  26136,  25616, -30358, -19079,   5945,
          11888,  16800, -28009,   1557,   6719,  -6048,  -2915,  11122,   5734,
         -11969, -10064,  25966,  42641, -19954,  27862, -31002,   3472, -22980,
         -14385,  -9169, -42243,   -170, -55846,  -8948, -40444,   4391, -22651,
         -13083,   -842,  24237, -36325,  49497,  53813, -32717,  18663, -22899,
          41903,   4567,   -329,  43351,  -1599,  11276, -39400, -16767, -21327,
         -10549,   9109, -24640,  -1088,  -4004, -12534,  31006,   7809,  11764,
          11367,  25420,  -3389,  33443,  28445,  -1826, -24991,   8348, -13985,
         -35472,   7014, -17080,  -4810, -16030, -13669,  32329, -16161, -10180,
         -11845,   5101,   4143,   3452,  52459, -13603,  16374,  14922, -25691,
          22476,   8281,  45839,  -6684,   1028,  -3952,  34647, -19254, -14584,
         -24336,   1466,   9665,   4919,   -356,  15881,  26809, -18702,  25131,
          28831,  -4804, -13188, -18459, -29674, -46822,  -6678,  37893,   3096,
          47679,   1455,  16632,  -6819, -31684,  40070, -26324, -22350, -36666,
          -8526, -17436,  39331,   7976,   7259, -17490,  13042, -36801, -40680,
           2821,  23069,   -375,  -1738,  -5469,  -2426,  12908,  54576,  -2930,
          33462, -16552,  34025,  -2640,  45549,    -52,  31134,  -4718,   7181,
          41818,  -4490, -44387,  19244,  -9231,  11506,  -1753,   5816,   4774,
          24074, -18122, -25605,  -8331,   5511,  -3326,   4300,  -4778,  26913,
         -18940, -22909,   6823,  34224,  11720,    233, -34764,  -8900,  35264,
          13444,   8553,   2420,  -6305,   9909,  31793, -11001,   3471, -14497,
          10461,  40848,   1993,  17598, -28789,  14907,  14875, -14308, -17298,
          -2129,  29572,   -796,  26946},
        { -8842, -15736,  33945, -16467, -23805, -45358,   1747,  11015,  31323,
          20880, -27257,  -3755,  28114,    -43,   1292, -32598, -28787,  -6607,
         -23241,  -9024, -21706,   5652, -21985, -36071,   1762,  -5777, -22333,
         -21161,  10149,  -8682,   8023, -22448,  30273,  34220,  33859,  31640,
         -17809,  -8218,  -5360,  -9601,   4276,   1271,  21684,  20588, -27679,
          -8154,  -6516,   7037,  15928,  19340,  -3687,  21227,  21893,  43593,
         -30304,   5434,    176,   1090,  -8990,  24482,  27308,   4889,  -6595,
          -6027,  30833,  24038,   1480, -17084,  -7473,  46036, -48964,  33253,
          -2209, -15222,   2166,  37308,  25043,  18217,  27853, -18878,  27114,
            -80, -17246,  10862,   2969,   3852,  45226,   5441,  -5657,  29493,
         -13832,  11741,  -9915,  31411, -18610, -18319,  20843, -13665,  -3018,
         -28000,  -1867,  -1031,   5281, -15997,  -6091,  42889,  12892,  19170,
           -885,  40856,  11052, -13367,   2450,  13187,  -1044,  -3781,   5619,
           1460,  33710,  -5556,  11303,   4087,  -4275,     14,  16031, -11832,
          28676, -20334,  -8971, -13767,  13075,   7145, -41208, -10973,  14200,
          21771,  -2138,   7024, -16261, -26057,  -1168,  22281, -12014, -14871,
         -23712,  -7035,  34722,   9137,  14759,   2462,  18375,  40486,  32373,
         -23385,  25713,  26567,  33327,  -6920,  22276,  28681, -16871, -46824,
         -21220, -13493,  12456,  11356,    964,  10664,  -6773,  -4420,   3072,
          18746,  27944,  40559,  46575,  40517,  -4241,  -8334,  24416,  11712,
          -1188,  37747,  19731, -19424,  14299,   3496,   8876,   3850,  10820,
         -12884,  11661,  44192,    826,  -1440, -24386,  -7219, -24475,   -268,
          29069,   7010, -16753,  13258,   1883,  -6814,  -5882, -16366,  48470,
         -28960,  -4627,  20603,   2271,    486,  11279, -30339, -11193,    121,
         -42028, -13631,  50748,  -7403,  36279,  -2155, -35079,  45809,  -7014,
          13134,  36555,  -5164,  14804, -10146,  -7575,  25877, -24902, -37328,
         -27128, -43947,   1743,  24029,  19268, -23423, -10710, -34822,  -4757,
         -35584,  17554,  12627, -26913,  14880,   9631,  26761, -12888,   8865,
          -9949,  16839, -32956,  23872},
        { 20996, -54214,  16042,  22669, -30776,  13794,  19427, -27212,  -7614,
          -2520,   6022, -36478,  -2508, -18075, -11319,  10438,  15132,  -8185,
          15829,   5057, -21709, -23202, -36465, -11275,  27987, -25605, -10450,
          31090, -13895,   6975,  -8229,  26085,  23254,  18572,  -6388, -17691,
          28182,  -2685, -13278,  25951, -19746, -16901,  -4120, -11097,  31499,
           4486,  11982,  -6133,  -3978, -13528, -17416,  -5617,  11700, -19808,
          11415,  32307,  20464,  -5836, -22331,  14014, -16172,  -2331, -27079,
             73,  -6047,  27511,  16184,   3065,  10094,  -7768, -14811,   9953,
          -3764,  18240, -11470,   3372, -22745,  -2360,  13451,  21777, -18802,
          10273, -18907, -35107,   3431,  13187,  16988,   5293,   1132,   1667,
         -43787,   3865,  25547,  14931, -29852, -14668,  15905, -16961,  41340,
           9135,  10021, -21368,  10827,   3907,  16963,  26859,   4505,  -7842,
         -45783, -12085, -19083,  19562,  -1959,  18302,   5657, -11502,  -7964,
          10943,   8082,   1214, -15767,  12702, -16681,  -2148,  30990, -21504,
         -23097,  -9457, -23818, -15791, -27927, -33695,  19656, -47451, -10328,
          14239,   3233,    637, -22858,   5579, -22263, -22441, -19762,  21325,
          -6293,  -9298,  11544, -11010,  -5129,  26326,   6360,   8652,  27417,
         -16990,  -9161, -16011,   5902, -26354,  -5786,   5591,  -8785, -18676,
         -12000,  11751,  23230,    899,  23953, -28835, -13567,   8081,  -8579,
           2283,    373,   1856,  -7107,  -1564,   7259,  11105,  -8408, -31053,
         -37891, -26858,  -3046,  17990, -16167,   4780, -21635,  25579, -23592,
          -4458,  -3606,   -983,  -3146, -15428,  25227,   7339,  28041, -25104,
            942,   9182,  10278,  30992,   8308, -19629,  -6492, -15924, -18453,
          12001,  -5762,  -5857,  -2905, -29919, -18398,   4164,   -184,  -9484,
          15987,  31119, -26067,  -4362,  10869,  -6095,  26456,  10760, -26995,
          -5601, -14993,  31080,   1435,   8217, -21610,  18780, -34576,   1159,
         -17964, -25197, -16423,  30782,  -1414,   9309, -14862,  -1804, -11367,
          13898,  14620,  21196,  -2245,   7361, -28375,  -1433, -11125, -16139,
          -5112, -12787,  39711,   4534},
        { 25290, -25769,  -6888,  26996,  25143,  18875, -33610,  19556,   5466,
           -202,  20468,  32939,   9488,  10201,  -9684,   4226, -23614,  -4273,
          -2844, -23289,   5461,  -5091,   8564,   1477, -17653,   -421,   2895,
         -15219,   1427,  -2568, -35527,  19197, -11831,  -3827,  17865,  -4132,
          28393, -19166,  28397,  17839,  16521, -11592,   8719,  -4985, -32024,
         -18604,  -7636,    642,  -1656,  -9357,   7699, -20522, -10623,   6198,
         -14909,  33263,    522, -15687,  24748,  -1413,  21950,  11991, -13038,
         -12943,  12654,  -7596, -23458,  15838, -13387,  15665,   2755,   6876,
          39525, -22180, -17061,  -1447,  17976,  -1923,    982, -20670,  26553,
           3215,  -4086,  -3473,  -4661, -18377,  -3909,  15112, -28526,   6231,
          20855, -19198,  14232, -13551,  -3503,  21570,  -9540, -19019, -33047,
           4593, -30758,   1290,   7513,  -7776,   4531,  -1722, -12663, -10899,
          35258,  18751,  19742, -32336, -14356, -23206, -21448, -14542,   3352,
          -5381,   2282, -14902,  -9862,  25228, -19623, -19758,  16388,  23371,
          -4991, -16448, -25363, -15787,   9978,  15050,  21034,  35415,  -8068,
          15493,  28783,  -2761,  21091,   7559, -10294,  -1498,  21862,  33149,
         -12671, -10244, -19356, -16710,  14739,  -2389,      5,   3780,  18029,
          11866,  -1313,  -2093,  26119,  -1635, -23218,   5603, -18440,    832,
         -24365, -13528,  -3319, -19199,   7028, -16373,  -8183,  -7852,   1725,
           5762,   1732,  20922, -28854,    241, -14165,  -5699,   2351,  14885,
          19531,  24458, -20623, -35113,   7537,  -7219,   1041,  -1702, -13567,
         -21494,  -7090, -12579, -19610, -25667,  20458, -21529,  24248, -19946,
          13994,  10541, -14239,   3469,  -6024,  15075,   2016, -24696,  -1632,
          -4280, -16136, -18318,    246,  23582,  10667, -10573,  13150, -28055,
          21258, -30259,   6530,  27586, -18399, -22330, -15153,  -9814,   9099,
         -22346,   4091,  10350,   1681, -17530,   8481, -23959,  30949, -19797,
           6132,  13044,   5869, -10397,  -9152,  11455,   9718,   3055,    961,
         -10331,   8233,  10900,  22762, -27493,    901,   -824,  10524, -11133,
         -34480,  -6613,  21801,  -2922},
        {-14433,  22799,   3725, -27443, -35061,  16426,  28867,  16623,  -7291,
         -15828, -22989,  -4679, -21399,  18067,   1090,  18331,  -1953, -20778,
           8705,   8487,  -2496,   4618,   5081,  -1625,  14124,  34325,  13004,
          -7921,  21439, -15560,  11909, -16122, -26134, -32886,  -4250,  -6237,
         -17459, -19269,  -4233,  29068,  33374, -14749,  -3277,  15579,   3952,
         -16525,  20471,   5579, -23061, -18383, -16620,  -1751,  -7987,   5903,
          10771,  -9418, -27237, -14163,    436,  -1079, -11974, -19007,  24254,
          40085,  12919, -18595,  25147,  -8554,  15717,  -6288,  -3432,  -3630,
          -4518, -22655, -27467,  13616, -24689,   6322,  14642, -23671,   4158,
          18155,    549,  16466,  40437, -21875, -22545,   7315, -16137,   1851,
           9615,   2544, -20191,   6919,  12231,  29301,  19256,   6166,  -8693,
          -3844, -31834,  36280,  12994, -18713, -45466,   7062, -11283,  20100,
         -24980,   7092,  26327, -21516, -14687,   1323,  22980,   1562,  -9961,
          -6920, -35086,  13177,  -5769, -35276,    207,  24221, -21857,  23363,
            712,  -5145, -24209, -15135,  19434,  25200,   6461,  -9516, -11329,
         -34770, -20691, -10126, -20541,   4777,  23445,  31355, -20205,  -2628,
          -7103,  -7237,   9892,  -2400,  -8832, -27819,  -3723,  28424, -19269,
           9928, -11574,   5352, -24873, -26247,  -8958,  -8920,  -8787,  -1697,
         -15983,   7936,  -8536, -12972,  -4180,  -2265, -12197, -10097, -18345,
          21113,  15737, -38568,  20515,  -5791, -14907,  -3050, -26190, -14376,
            -26,   1683,   5623,  -5345, -21339, -17781,   2580,  16038, -14049,
          -8079, -16877,  24893,  22171,  24728,    602,   7905,   6078,  10718,
          11507,  15113,  -3306, -36075,  19238,  13673,    -11,  17642,  -2545,
          -9533,   2141, -16466,  -2268, -28513,   9126,   9930,   3930, -28664,
          -9750, -16604,  -8398,  14153,   8003,  35143,  -9481,  30991,  17611,
         -21500,  23719, -30248,   8244,  -3905,  26035, -31629,  24799,   7092,
         -26054, -12981,  -8519,  -8783, -26961,  -9659,   9880,  -8546,  11689,
           1830, -31398, -28094, -27203,  11429,     51, -13441,  14765, -19228,
          -6109, -11331, -28821, -10741},
        {-28544,   9335, -16486, -25600,  11648,   8865, -31848, -15658,  -5041,
           9242,   3327,     26,  15206, -32173, -18437,  -4687,  -6237,  17297,
          -2699,   5334,   2543, -24728,   8755,  -2437,  -9766, -21681,  11790,
          12390,   5065,  12979,  24340,   -151,   9542,  29536,  19000, -12362,
          26805,   8968,  10764, -24663, -15887, -19512,  20520, -10855, -20023,
          21353,  -3990, -14248,  -4372,  21859,  19177,  -8481,   7713,   7727,
         -22925, -24710, -36672,   -940,   1670,  -8803,   8509,  15457, -21572,
          26361,  13010,  11304, -25633,  17491, -29020, -13330,   7738,   8442,
         -12219,  -1492, -12081,   3366,  24324,   8956,  13532,  26000,  10237,
          12971,  -3691,  -7549,  51342,  28344,   -794,   1268,  29890,   3777,
         -36570, -21505,  15244,  15156,  -3118,    833, -23422,  -5333,  -8109,
         -25369,  11935, -14975, -19929, -10960,   5896,  27682,  -5197,  -2934,
            272,  -7824, -24828, -31466,   1476, -24146,  -3742,   5059, -17809,
          -9113, -18202,  14331,   -442,  -9475, -18440,  10612,  -6819,    773,
          -8023,   7054,  18482, -14604,   3911, -32618, -23515,  -9967, -29031,
         -20793, -33168,  -5100,  18891,  18872,  18495,  25222,  20474,   6225,
          -1022, -16764,  -6316, -12933, -14448,   6304, -23160, -22128, -21070,
         -19461,   -461, -10009, -14867,  22600,    -12,   8127, -12861, -15256,
          -9662, -16569, -18133,  -1366, -27584,  -3997, -12583,  -6171,   1069,
          -9719,  -4789,   3550,  24318, -10317,   3616,  21244,   9106,  29885,
         -37654,  -6604,   5406,  26578,  -1803, -15174,    372,   4688,    221,
         -19702,  15279, -17005,  38397,  36434, -15854,  16248, -28645,  22756,
          -1817, -12876,   -148, -18639,  23022,   3917,  -3598,  16127, -14717,
          13705, -10742, -14519,  -2060,  16995,  -2400,  24636,  11891,  23285,
           6352,   1372,  -1497,  18660,   6119,  24001, -21568,   6025,  11896,
          -7365,  23260, -42951,   1424,  -7863, -19585,  -4016,  24275, -16088,
          28223,   3277, -26248,  23792,  19941,  13067,  -5801,  10396,  -4599,
           8672, -17337, -33771,   9397,  26871,  -6603,   -407, -20318,  -6855,
          19524,   2482, -19355,   7293},
        {-30125, -34637,   1701, -32713,  19442, -13899,  17830, -10076,  27171,
           9208,   3329, -33880,   5566,  25412, -10299,   8260,   5563,  26383,
         -13826,  -2357, -23030, -16621, -35895,  20619, -42937,  -4408, -23141,
          26718, -12912,  -6840,  -1227, -23846,  24503,  14999, -15732,  36923,
          -1567, -15598, -24650, -14207,  24506,  -1054,  18632,  -5094,  24215,
         -19634, -19064,  17709,  -7067,  -1188,  20421,   9062,  18933,  -8830,
          -8302,  -2854, -27877,  -9847,  25620,  12377, -36069,  16554,  -3664,
           2323,   5368, -27161, -13140,   6280, -28288,  10172,  28062,  36019,
          11955, -18073,  -1497,  14361,    742,  -6466,   4809, -24875,   7526,
          -1363,  15230,  27980,   7966,  -4505,  21169,   -137, -30366, -17750,
         -37335,  -3042,  11664,   3108, -12545,  -6402, -11802,  -7784,  25437,
          10920, -11718,  -3335,  15762,   8145, -30973,  12312,  -4964,  18686,
         -53474,  19555, -36698, -22986,  -8006,  -6059,  14122, -18797,  11905,
         -18178,  21063,    972,    560,  25909,   6205,  -5069, -31511,  25492,
           1665, -28569, -20900,   2888,  25943, -33733,   2859, -52248,  12979,
          20090,  -8651,  25071, -25768, -20380,  33608, -19746, -30634,  -5432,
          19607, -20075,  -1891,   4150,  17620,  26345,  25543,  -2858,  24234,
           2928,  32255,  -1518,   5344, -32856,  -7734,  14674,  -8370,  27357,
          18589, -11559,    878,   -212, -27063,  34029,  -5707,  23665,   -696,
          22764, -17123,  25263, -18345,   2259,  16660,    261,  17238,   9911,
         -19803,  33773,  19542,  16013,  14459,  -6393, -24305,   4496,  31319,
          10633,   3539, -13528,  14285,  20220, -17035,   5453,  24155,  25764,
          30326,   3783,  -6930, -33014,  13104,   4763,   3071,   6174,  26931,
         -19726,    476,   9647,  25003, -38343,  25375,   4557, -11824, -31000,
           3304,  37277,  -2015,  18860,   5575,  17106,  16574, -18235, -29335,
          -1184, -25677,  34711,  -5468, -17065, -43166, -18576, -49584,  13317,
         -47243,  14853,  12529, -23247,  18527, -26071,  -9421,    939, -17541,
          -1398,  16410, -26907,    -67,  -8629,  44787,  25237, -28156,  -5439,
         -30980,  -4993, -26884,  12727},
        {-32262, -33814,   9240, -36662, -35125, -24161, -45915,  -5083,  24606,
          10319,  11537,  10802,  -9713, -14011,   7554,  -5830,   3938,    200,
         -17560, -36101,  -9499,  15804,  -8114,   8504,   6759, -39152,  -1023,
         -16844,  19038, -15337,  29808, -24395, -11124, -22409, -14244,  23852,
         -13413, -12670,  18149, -30017, -11758, -11606,   9238,  16171, -19069,
          28963,     96,  -3624,   1922, -27286, -18939,  19934,  18919,  17046,
          15910, -14678,  -9423,  -4917, -10284,  26593,  -8769, -30576,   4597,
           5445, -12330,  -7902,  31031, -11864, -13562,  18092,  11869,  35904,
         -20272, -30920,  -2529,   8469,   2606,  13325, -14144,  22855,  20929,
           4545,  11972,  11326,  21157,  23468, -16766,  12066,  -1290,  -1362,
          26770,    322,   2496,    866, -29687, -19493,  -4040,  20588, -48046,
         -21694,  29764, -40334,   6494, -11240,  -9441, -21011, -12910,  -4662,
          29792, -21027,  -5270, -43248,    -86, -26796,  29805,   4227,  -2515,
         -19508,  24376,  -1125,  19958,  26631,  -2132,  15713, -18860, -26467,
           8232,  -5922, -28059, -11425,  11272,   2103, -16762,  26536,  -6414,
           3597, -32277,  27957,  17050,  -8945,  26582, -34665,  21407,  -7807,
          19440,  -6483, -17182,  10138,    733, -23807,  13688,  11897,  24132,
           7064,  16726,    -55, -14885,  -2971,  22329,  29520,  -4623,  -1870,
          28045, -13116,  20401,  -3092,  -8645,  18388,   2134,  31580, -18566,
          -4812,   9865,   4117, -31150,   8318,  22184,   -505,  -6558,  -9068,
          37689, -11611,  29443, -25282, -17966, -16855,  -1049,  -6832,  15517,
         -14597,    729,  26981,  34686,  30091, -12170, -28676,  -6457,  19474,
           5293, -19466,  22559,  -4408, -12940,   4768, -19500,  16834,  14556,
           1451,  -3340,  10764,  22495,  -7705,  -8297,  17879, -13773,  25320,
         -12675, -12066,   8584, -11348,  28944,  35463, -30118,  -3321,   2372,
          11027,  -8305,  22627,  -8268,  26775,  -7307,   6795,   1283,  -9033,
          12998, -29449, -20634, -32555, -32191,  -6877, -14446,  11895, -13531,
          12403,  24456, -18667,    303, -36039,  20977,  32942, -15805,  -6239,
         -12162,   2947,  -6990,   2327},
        {  7668,   7985,   1551,  24151,  23772,    769,  16050, -26839,  22312,
          18715, -17342,  22962,  14075, -13189,  -2661, -12187, -17501,  27259,
         -11073,  -2824, -10299,  -6218,  15771,  20912,  -5038,  19815,   3697,
          -1538,  14090, -18862, -24609,  21303,  15294,  21134, -12707,  20340,
          -7491,  -7156,  20105,   8667, -34341, -17109,  16921, -15354, -35468,
           3474, -32011,  -3959, -14649, -11934, -22621,  17940,  21836,   2534,
          -8278,  29993,  20638,  -4256,  22805,   3890, -44909, -31321, -36060,
         -36396,  -2765,  16972, -22806, -17411, -11264,  -7696,  22790,  32580,
            502,  -2419,   4957, -11572, -35771,   5635,  -3867, -14747, -14968,
         -15333,  -4899, -15717, -27178,  30000,   2120,  -2096, -15805,  -8518,
         -33804, -12409, -41308,  11900,  15112,  20652,   2360,   8303, -19811,
          -2827, -20699,  10866,  -6727,   -803,  22209, -16793,   8535,  -8481,
         -12231, -12812,   7058, -20129, -11033,  15440, -10419,  -2944,  13599,
         -10505, -22813, -14846,  17555, -15336,  -6713, -31026,  17055, -24557,
           2811, -21191, -23834,  10681, -15014,  -1853,   3748, -16078,  -2893,
         -15554,  18880,  14172, -16222,  -5519, -10561,   8921,  -7196,  24592,
          21254,   3540,  -4545,   6815,  24673,  -2158,  -4492,   8307, -22602,
         -16044,  27155,   2819,  19608,   8096,  12032,  20529,   6153,  12248,
          23275,  -9695, -19623, -10163,   2746,   4546, -14652,  15471, -13574,
           8370,  -1473, -19159,  34468,   1326,  11695,  11767, -22654, -27590,
         -27871,   2749,  25917, -38476,   6635,   4658,   4565,  -3288,  21074,
         -13902,  16422,  -6422, -10716, -19741,   7135,   8454, -29084, -12613,
           1237,   5847,   4190,  33227,  -3609,  -1620,  -5059, -33209,   3928,
           5149,   -384,   5646,  20358, -43851,  -5525,  -1909, -16402, -24105,
         -13647,   1924, -15656, -26492,  19674, -25541, -19036,  21474,  -4323,
           7452,  -3881, -34223,   7864,  15093,  19717,  24635,   2709, -20543,
         -29566,   6537,   2811,  24046,  -6973,  11031, -16324,  13760,  11051,
         -13646, -23548,  25110,  15611,   9869,  16406,  28987, -17078, -16992,
         -30679,  -1871,  41810,  -6707},
        { 12801,  31913, -18985,  20920, -21008,  15579, -27032,  19684,  20246,
            666, -30871, -46529,   8052,  36835, -11326,  -6779,  18817, -12295,
           7692,  11037, -37246,  22349,   -726,  14777, -39239, -14874,  16032,
          13547,  20625, -16836, -33100,   7000, -24941,  -8897,  11883,  31106,
          14682, -14416, -24386, -12359,  22480,  -2865, -13634,  -5812,   -812,
         -26426,  -9946,  16233, -10231, -29277, -13593,   8279,   4602,  15625,
          24708,  27066,  27612,  10560, -15117,  -8513,   6982,    364,  -7483,
         -19408,   4682, -29252,  29511,   3732,  28047,  15539,   8329,  23594,
          -8269,  16091,  -8540,  17992,  12551,   2191,  -5956,   8984,   8079,
           1640, -10111,  14496, -37264, -39449, -20459,   9279,  35002,  -3869,
         -22902,   1805, -23616, -24245,   2451, -21664, -37579,  10531, -22324,
          12034, -22422, -21514, -14424,  -5397, -15079,   9015,    -63, -39459,
         -42043,  16058, -39914,  28443,  -6549, -42730,  16620,   1393,  28747,
          -8393, -18286,  -5720,   7325, -37758,   4957, -15508,  12115, -31449,
          22142, -13691,  21090,  -7785,   3501, -47686,   2016, -29757,  16717,
         -12225,  33919,  15140, -38768,   7625,  -6266,  17737,  -1505,  15203,
          21225,  11286,  25269,   9775, -19878, -25136,  16581, -31820, -18576,
          18717,  23858,  14933,  16720, -39443, -14488,  11592,   4893,  11789,
          23534,  -5590, -11367, -10894,  24381,  13511,   7393,  11380, -11156,
            229,  13984,   4997,  10270,  12656,   7136, -17641,  10850,  30504,
         -25533,  21481,  25591,  28315,   -762,  -8985,  18031, -24093,  12468,
          -7689,    355,  -7938, -27055, -31992,  23230,   8498, -19329, -23006,
          24650,   2321,  18697,  18919,   9235,    651,  14278, -37451,  25376,
          11763,  -2810,   3195,  18563,   6280,  19567, -16474,  -7479, -14777,
         -17461, -11625,  18653,  -6309,  15599, -13927,   9186,  -5131,  -8231,
          12309,   6844, -18269,   2725,  11235, -55575, -10974,   1273,  13046,
          -5745, -17089,  20633, -16368,  -5354,   9009,  -7925, -12681,   3779,
          16612,  10512,  27686, -10718,   5569,  30307,  15715,  31623,  -1404,
          24012, -17824,  33173,  10938}
};

static const int32_t bias_1[BIAS_1_COLS] = {
          7507,  20723,   5664,   9249,   6047,  49623,  13298,  -3429, -18686,
        -18541,  10460,  12289, -23620,  -9704, -21539,  -8157,   4538,  -7445,
         -8113,  41476,  14242,   -801,  26203, -21490,  12036,  -1103,  11893,
          9252, -10109, -18728,   3826,  -6208,  -1854, -10457,   1476, -24217,
         24503, -19195,  -4469,  33634,  -7027,   6996, -20922, -20957,   4921,
          1477,   4955, -13740,   7826,   2402, -11326,  -3083, -13322,   -612,
         -4161,  -9511,   5567, -20349, -12551,  -3823,  10426,   9224,   -431,
         -5247,  10426, -13414,  -5677,  53117, -13817,  -6650, -19238, -38185,
        -13735,  -4243,  -1682,   5558,   9474,  -2031,  33393,  -1463,  -5338,
         38591, -16295,  -4263, -11839, -15157,   5436, -12342,  -8562, -27161,
         13859, -21205,  29947,   5060,  13026,   -632,  20199, -21737,   4125,
          8778,  -6094,   1306,   5502, -12102,  10859,  -3189, -26386,  12771,
         16723, -17579,  16032,   3053, -13947,  14983, -12812, -19946, -15283,
        -16616,  10960, -18810,    898,     13, -19927,   4504, -13356,   1162,
          2831,   2117,   1467,   -657,  -2599,  17923,   5678,  29333, -11344,
          3655,   -114, -19758,  -2127,  -2940, -11817,   3542,  -3269,  -8293,
        -20172, -14193,   8323,  -1420, -23523,  -1499, -13555,   7352,  -7996,
         -4910, -24635,   8467, -22178,  11710, -10910, -21533,  -7771, -12332,
        -14010, -21259,  -9332, -20228,     57,  -9276, -11451, -22168, -12685,
        -11147, -15024,  -7522,   1541,   1007, -20389,  -2444,  25918, -10120,
         -2030,  -8426, -24828,  21094,  -9912, -19110,  17154,  26971, -12674,
        -14444, -20527, -11738, -11075,  -4324,  -6490,  18507,   3967,    975,
        -31196,  32800,  -6273,   -381,  -4225, -20792,  15294,   7055, -12023,
         12175, -12422,  -3219, -20465,  25490, -19827,  -8116, -16553, -10862,
         37269, -10051,  12300, -10037, -26271,  -9655,    206,  -7735,  20340,
         -7632,  21914,   7269,  10236, -20759,  34843, -10032,  43915,  -2802,
          3868,   5809,    943, -16105,    880,  32288, -16547,  -5674, -22806,
        -13651,    649,    789, -14103,  29542, -28407, -18956, -17270, -15201,
          9251,   5073, -14495,  -7382};

static const int32_t weights_2[WEIGHT_2_ROWS][WEIGHT_2_COLS] = {
        {-11976,  26756,  21657},
        { 33248,  -1732, -12530},
        {  6355,   8049, -15441},
        {-22130,  37493,  31248},
        {-51729,  -1897,   5234},
        { 20509,  13112,  22924},
        { 28880,   4457,   6056},
        { -5531,  15304, -12832},
        {-11726, -20398, -19801},
        { -6227, -13294, -10798},
        { 10322, -14196,   8158},
        { 16753, -21320,  12138},
        { -8340,  -7308,  -8378},
        {-27996, -15331,    357},
        {   383,  -1456,  -3830},
        {  2814, -22479,   4822},
        {  6265, -27820,  11447},
        {-19091,   4016,  -6872},
        {-12483,   -720,   8830},
        { 29848,   2845,  14043},
        {  3380,   -374,   8357},
        { -9380,  14891, -16979},
        { 23477,   -414,  13197},
        {-13749, -15677,   -604},
        {-16958,  29421, -19104},
        { 28045, -13139,  22922},
        { 14589,  -3524,   7544},
        { 20035,  20198,  23387},
        {  8447,  -1453, -14731},
        { -1765,     74,  -3238},
        {-30937,  15887,   8861},
        {-11267,   9039,  19269},
        {  9813,  11144, -39650},
        {  -318,  18287, -23066},
        { 10858,   9811, -20491},
        {-19063, -22236, -19514},
        { 18770,  28908,  18586},
        { -2834,   1943,   1204},
        { 10383,  -7996,  22156},
        { 18080,  32401,  25481},
        {-40193,   8020,   1662},
        {   633,   5019,    -65},
        { -9139, -12326,  -8994},
        {  -565,   7544,  -2697},
        { 16060, -11956,  17999},
        {-30846, -17141,   5897},
        {-21622,   9401,   2970},
        { -4598,  -9190,  -2402},
        {   608, -22349,  -6878},
        {-12239,   9829,  -8316},
        {-20373,  26905, -11748},
        { -5079,   4047, -20214},
        {-18400,   7208, -11738},
        { 10484,    701, -15828},
        {-26370,  -3947,   6267},
        { -1637,  31454,  10256},
        {-43971,  16552,  16561},
        {  1700,   -162,   3924},
        {-14485, -14770,   7698},
        {  4423, -13607, -17438},
        { 22790,  11468, -21944},
        {  3298,  23334,  -2880},
        {-34241,  16704,   7945},
        {-19958,  20679,  23393},
        { 10434,  -1826,  -1944},
        {-14180,  11425, -30103},
        {-33141,    569,  -6164},
        { 14505,   9835,  15956},
        {-26848, -11122,   6261},
        {  3795,   4946, -32621},
        {-24693, -18344,   1361},
        {-19978, -17501, -29359},
        {-24703,  15891,   7457},
        {  4717,   5656,  21523},
        {  -663, -10722,  -2111},
        {  9724, -13875,  -9814},
        { 11558,  27219,   4230},
        {  4289,  -9045,  -5437},
        { 10281,  17948,   8986},
        { -4490, -14104,  17466},
        { 17808,  23149,  -8038},
        { 24602,  12111,   5945},
        { -2108,   -606,    461},
        {-21740,  10580,  -1865},
        {-41559,  19775,  17480},
        {-27921,   3700,  -4635},
        { 19605,  15326, -27891},
        {   -50,   5942,  -5823},
        { 32270, -11237,  23237},
        {   283,    654, -20624},
        { 21395,  19807, -23824},
        {  -939,  -1100,  -2740},
        { 22527,  -2353,  12420},
        {  -799,  20613,  -1301},
        { 19288, -30904,  14677},
        { 15280, -24932,  21149},
        { 19758,  16749,  -3655},
        {-17719,  -1965,  -6966},
        { 36492,  16025,  17226},
        {  3297,  -8676,  14080},
        {-24652, -10936,  15446},
        { 21910, -11081,  21836},
        { 11179, -15075,    581},
        {  3225,    -57,  -2166},
        {-10860,   -195,  10826},
        { 28942,  16008,    807},
        { -5779,  -3121,  -4808},
        { 10954,  13243,   8239},
        { 29596,   2926,  28702},
        {-11319,  -4500, -14779},
        { 32844,  19063,  15210},
        {-16257, -12455,  30317},
        {   854,  -1198,   1927},
        { 21987,  19830, -13258},
        {-21390, -11430,   1763},
        {  1802,   2116,  -1946},
        {-14991,  -4628,   -551},
        {  3875,  -1293,  -1944},
        { 16230, -18023, -26445},
        {   -31,   -815,  -2741},
        {   481, -15170,  -6854},
        { 21131, -27677,  -1797},
        { -1555,    932,  -1271},
        {-34369,  15549,   9486},
        {-20144,  14931,  13578},
        {-37780,   6916,  16155},
        {   681,   7444, -18156},
        {  1708,     67,   2467},
        { 26810,   3826,  -2883},
        {  1046,   1866,    463},
        { -8752,  12059,   8033},
        { 30566,  15776,  10900},
        { 10883,  -1314,  21741},
        { 30936,  23145,  25344},
        { -5852,  -5363,  -4999},
        { 14648,   -721, -13448},
        {-25205,  13857,  15564},
        { -7691, -13674, -12932},
        { 13153, -12637,  22819},
        {  8328, -22872,   9997},
        {-45329,  12247,   9500},
        { 30734,   3847,  -1404},
        { 15139,  -5090,  14655},
        {-12952,  22880,  16028},
        {-10658, -27343,  -9762},
        {  -758,  -2240,    865},
        { 10687, -11056,  -3234},
        { -1590,   -335,  -5790},
        {-19516,  -2347,  -2052},
        { 18059,  20248, -22838},
        { -5659, -19244,  -8390},
        { 21799,  12836, -11253},
        { 21886,  -1401, -38159},
        { -2390,   7622,  -4492},
        {-23090, -12709, -19830},
        {  4963,   -271,  -1594},
        {-14414,   4189,  -3982},
        {-16156,  -6030,  20510},
        { -8707,  -5496,  -8651},
        { -7910, -18625, -12570},
        {  2985,    195,   2355},
        {-20807, -23323,   8270},
        {-11499, -26282,  -9666},
        {   545,  -2182,  -2272},
        { -2460,  -5516, -20621},
        {  2026,  -1410,  -2079},
        {-29649,  22395,   6775},
        {-17970,   3119,  -6210},
        { -2623,  -2998,   -751},
        { -7991, -27156, -14135},
        {   738,  -3766,  -2223},
        {  7317, -21890,   -256},
        { -7819,   3022, -12683},
        {  8026,  -2656, -32204},
        { 30983,  18336, -36998},
        {  2185,   4807, -17727},
        { -7312, -22100, -10317},
        { -5201,   9663,   5861},
        { 15751,  15736,   -819},
        {  9902,  24440,  -5227},
        { 27840,  24055, -20461},
        {-27230,  13814, -11651},
        { -9671, -25211, -20074},
        { 26881,   6565,  27277},
        { -6548,  -5001,  -5282},
        { -2817,   2359,    556},
        { 11831,   3362,   5298},
        { 17923,  22380,   9576},
        {-34387,  -4276, -10148},
        {   225,  -2184,  -2500},
        { -7063,  -6102,  -8795},
        { -6596,   8399, -31713},
        {-37927,  13895,   9935},
        {-57116,  23727,  20230},
        {-25076,  17575,  18275},
        { 20330,   2143,   6452},
        { 19253, -30599,  10058},
        {-26686,  14154,  14784},
        { -9053, -17411, -12707},
        { 11285,  16285,  12973},
        { -5819, -22019,     73},
        {-30193,  16621,  14491},
        { 13655, -14985,   3657},
        {  2147,   -452,   3344},
        {  7333,  -3982,   4498},
        {-13147,  20075,  20793},
        {-21180,  -5211, -28103},
        {  4343,  -7222,   9194},
        {  3943,   -393,   3877},
        { -6543,   2007, -10322},
        {-11907, -22126, -13937},
        { 28818,  17301,  -4592},
        {-17751,  -6561,  -9148},
        {-27735,   5550,   7140},
        { -1515,   2276,   1614},
        { -8794, -11046,  20585},
        { 10120,   9163,  12675},
        { 30951,  16475,   -171},
        {  8583,  11596, -24371},
        {-29227,  14944,   9739},
        { -9982,  -7278, -21257},
        {-54273,  13650,  16585},
        { 12210,  -5109,  18115},
        { 17747,  15775, -41474},
        { 15964,  -1952,   6802},
        { -3512,  -2630, -11448},
        { 21244,  14779,  -3834},
        { 26806, -33845,  -4348},
        {  7368,  -3620,   -171},
        {-11792, -17233, -15410},
        { 31368,  28391,  23754},
        {-17242,  15796, -26499},
        { 38072,  11564,  19758},
        { -2319, -18373,   7805},
        { 20071,  -5962,  23882},
        {-19707,    474,   5447},
        {-17179,  -1980,   3250},
        {-17193,  21673, -18138},
        {  8517,   2549, -28746},
        { 12689,    663,  12800},
        {  -117,  -1517,  -3791},
        { -9257,  -7782,   7099},
        {   -94,    482,  -2690},
        { -8470, -10292,   6646},
        {  8602, -24049,  -9465},
        {-21697,  20522,  17770},
        { -2098, -16776,   7530},
        { 29739,  20244,   2435},
        {-32819, -11730, -13381},
        {-21684, -18873, -20195},
        {-22772,  10770,   -733},
        {   177,   2508,  -2201},
        { 16009, -24683,  10669},
        {  4784, -18895,  -8249},
        {-29543,  22612,  23833},
        {   549, -10966,  -6585}

};

static const int32_t bias_2[3] = {
    13386, -1466,  5492
};

#endif