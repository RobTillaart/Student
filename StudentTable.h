#pragma once
//
//    FILE: StudentTable.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Arduino library for Student or T-distribution math.
//    DATE: 2024-07-22

//  lookup table, do not change.
//
//  spreadsheet = ROUND(1000 * T.INV.2T(C$4;$B7))
//
//  x = degrees of freedom
//  y = confidence level 0.1, 0.05, 0.025, 0.01, 0.005 (right only)
//  values are multiplied by 1000, to save RAM.
//  


//  uses 200 bytes of RAM
uint16_t StudentLUT[20][5]
{
  // 80%   90%    95%    98%    99%
  //---------------------------------
  { 3078, 6314, 12706, 31821, 63657},  //  n = 1
  { 1886, 2920,  4303,  6965,  9925},
  { 1638, 2353,  3182,  4541,  5841},
  { 1533, 2132,  2776,  3747,  4604},
  { 1476, 2015,  2571,  3365,  4032},

  { 1440, 1943,  2447,  3143,  3707},
  { 1415, 1895,  2365,  2998,  3499},
  { 1397, 1860,  2306,  2896,  3355},
  { 1383, 1833,  2262,  2821,  3250},
  { 1372, 1812,  2228,  2764,  3169},

  { 1363, 1796,  2201,  2718,  3106},
  { 1356, 1782,  2179,  2681,  3055},
  { 1350, 1771,  2160,  2650,  3012},
  { 1345, 1761,  2145,  2624,  2977},
  { 1341, 1753,  2131,  2602,  2947},

  { 1337, 1746,  2120,  2583,  2921},
  { 1333, 1740,  2110,  2567,  2898},
  { 1330, 1734,  2101,  2552,  2878},
  { 1328, 1729,  2093,  2539,  2861},
  { 1325, 1725,  2086,  2528,  2845}   //  n = 20
};


/*
  { 1323, 1721, 2080, 2518, 2831},   //  n = 21
  { 1321, 1717, 2074, 2508, 2819},
  { 1319, 1714, 2069, 2500, 2807},
  { 1318, 1711, 2064, 2492, 2797},
  { 1316, 1708, 2060, 2485, 2787},

  { 1315, 1706, 2056, 2479, 2779},
  { 1314, 1703, 2052, 2473, 2771},
  { 1313, 1701, 2048, 2467, 2763},
  { 1311, 1699, 2045, 2462, 2756},
  { 1310, 1697, 2042, 2457, 2750},   //  n = 30


40	1303	1684	2021	2423	2704
60	1296	1671	2000	2390	2660
120	1289	1658	1980	2358	2617
10000	1282	1645	1960	2327	2576  //  effectively infinity.
*/

//  -- END OF FILE --

