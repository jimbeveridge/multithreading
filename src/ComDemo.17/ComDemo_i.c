/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.00.44 */
/* at Thu Oct 31 17:27:14 1996
 */
/* Compiler settings for ComDemo.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IAutoIncr = {0x8C758992,0x1EF9,0x11D0,{0xB1,0x42,0xDC,0xC5,0x19,0x00,0x00,0x00}};


const IID LIBID_COMDEMOLib = {0x8C758990,0x1EF9,0x11D0,{0xB1,0x42,0xDC,0xC5,0x19,0x00,0x00,0x00}};


const CLSID CLSID_CAutoIncr = {0x8C758996,0x1EF9,0x11D0,{0xB1,0x42,0xDC,0xC5,0x19,0x00,0x00,0x00}};


#ifdef __cplusplus
}
#endif

