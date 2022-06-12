#ifndef _CPU_H
#define _CPU_H
#include <stdint.h>

typedef struct CPU_STRUCT
{
	union
	{
		struct
		{
			uint8_t al;
			uint8_t ah;
		};
		uint16_t ax;
		uint32_t eax;
		uint64_t rax;
		
	};

	uint64_t rbx;
	uint64_t rcx;
	uint64_t rdx;
	uint64_t rsi;
	uint64_t rdi;
	uint64_t rbp;
	uint64_t rsp;
}TY_CPU;

typedef enum _op_t
{
	MOV,
	PUSH,
	CALL
}TY_OP;

typedef enum _od_class
{
	IMM, REG, MM_IMM, MM_REG, MM_IMM_REG, MM_REG1_REG2,
	MM_IMM_REG1_REG2, MM_REG2_S, MM_IMM_REG2_S,
	MM_REG1_REGS_S, MM_IMM_REG1_REG2_S
}TY_OD_CLASS;

typedef struct _od_t
{
	TY_OD_CLASS type;
	uint64_t imm;
	uint64_t scal;
	uint64_t reg1;
	uint64_t reg2;
}TY_OD;

typedef struct _instruct
{
	TY_OP op;
	TY_OD src;
	TY_OD dst;
}TY_INST;

TY_CPU cpu;
#define MM_LEN 1000
#define INST_LEN 1000
TY_INST program[INST_LEN];
uint8_t mm[MM_LEN];
uint64_t decodeOd(TY_OD od);
#endif
