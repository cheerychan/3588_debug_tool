#include "def.h"

extern VIDEO_PCI_PROP video_pci_prop;

DBG_CMD_STRUCT dbg_cmd_table[] = {
	{"?", do_dbg_help},
	{"q", do_dbg_quit},
	{"help", do_dbg_help},
	{"mmio", do_dbg_mmio},
	{"ts", do_dbg_ts},
	{"vcore", do_dbg_voltage},
	{"sf", do_dbg_flash},
	{"prog", do_dbg_program_fw},
	{"dump", do_dbg_dump_fw},
	{"print", do_dbg_print_info},
	{"clk", do_dbg_clk},
	{"memtest", do_dbg_mem_test},
	{"i2c", do_dbg_i2c_test},
	{"dp", do_dbg_dp_test},
	{"efuse", do_dbg_efuse_test},
	{"ct", do_dbg_cts_test},

};

#define DBG_CMD_TABLE_SIZE (sizeof(dbg_cmd_table) / sizeof(DBG_CMD_STRUCT))

void CToolParserCmd(void)
{
	char *line;

	line = (char *)malloc(STRINGBUFFERSIZE);
	memset(line, 0, STRINGBUFFERSIZE);

	while (1)
	{
		EchoWait();
		CToolGetInput(line, STRINGBUFFERSIZE * sizeof(char));
		if (ProcessString(line) == 0)
		{
			break;
		}
	}
}

int ProcessString(char *buffer) // return 0 if quit, else return 1
{
	int bStatus;
	int i;
	char delim[] = " \t\n,";
	char *cmd[MAX_PARAM_COUNT];
	unsigned char param_count;
	DBG_CMD_STRUCT *p_cmd_struct;

	for (i = 0; i < MAX_PARAM_COUNT; i++)
		cmd[i] = NULL;

	cmd[0] = strtok(buffer, delim);
	if (cmd[0] == NULL)
		return 1;
	for (i = 1; i < (MAX_PARAM_COUNT); i++)
	{
		cmd[i] = strtok(NULL, delim);
		if (cmd[0] == NULL)
			break;
	}

	param_count = 0;
	while (cmd[param_count] != NULL)
	{
		param_count++;
	}

	/*Just for debug
		printf("\n");
		i = 0;
		while (cmd[i]!=NULL)
		{
			printf("%s ", cmd[i]);
			i ++;
		}
		printf("\n");
	*/
	for (i = 0, p_cmd_struct = dbg_cmd_table; i < DBG_CMD_TABLE_SIZE; i++, p_cmd_struct++)
	{
		if (strcmp(cmd[0], p_cmd_struct->name) == 0)
		{
			bStatus = p_cmd_struct->execute(cmd, param_count);
			break;
		}
	}

	return bStatus;
}
void writel_dp(int addr,int value){
	int reg_data;
    writel(value,video_pci_prop.mapped_mmioBase + addr);
	//writel(reg_data, video_pci_prop.mapped_mmioBase + reg_index);
	//reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
	reg_data =readl(video_pci_prop.mapped_mmioBase + addr);
	printf("\nRead MMIO %x = 0x%08x\n", addr, reg_data);
}
void do_mm_write_DP8(void){         //8G

writel_dp(0x00000020,0x50);
writel_dp(0x00000024,0x0c);
writel_dp(0x00000028,0x83);
writel_dp(0x0000002c,0x06);
writel_dp(0x00000030,0x20);
writel_dp(0x00000034,0xb8);
writel_dp(0x00000038,0x0f);
writel_dp(0x0000003c,0x0f);
writel_dp(0x00000040,0x04);
writel_dp(0x00000044,0x00);
writel_dp(0x00000048,0x26);
writel_dp(0x0000004c,0x22);
writel_dp(0x00000050,0x24);
writel_dp(0x00000054,0x77);
writel_dp(0x00000058,0x08);
writel_dp(0x0000005c,0x00);
writel_dp(0x00000060,0x04);
writel_dp(0x00000064,0x48);
writel_dp(0x00000068,0x01);
writel_dp(0x0000006c,0x00);
writel_dp(0x00000070,0x01);
writel_dp(0x00000074,0x64);
writel_dp(0x00000078,0x35);
writel_dp(0x0000007c,0x00);
writel_dp(0x00000080,0x79);
writel_dp(0x00000084,0x79);
writel_dp(0x00000088,0x11);
writel_dp(0x00000090,0x00);
writel_dp(0x00000094,0x10);
writel_dp(0x00000098,0x53);
writel_dp(0x0000009c,0x1b);
writel_dp(0x000000a0,0x0d);
writel_dp(0x000000a4,0x01);
writel_dp(0x000000a8,0x54);
writel_dp(0x000000ac,0x01);
writel_dp(0x000000b0,0x1a);
writel_dp(0x000000b4,0x04);
writel_dp(0x000000b8,0x17);
writel_dp(0x000000bc,0x61);
writel_dp(0x000000c0,0x01);
writel_dp(0x000000c4,0x21);
writel_dp(0x000000c8,0x2c);
writel_dp(0x000000cc,0x0b);
writel_dp(0x000000d0,0x23);
writel_dp(0x000000d4,0x00);
writel_dp(0x000000dc,0x00);
writel_dp(0x000000e0,0x00);
writel_dp(0x000000e4,0x00);
writel_dp(0x000000e8,0x00);
writel_dp(0x000000ec,0x00);
writel_dp(0x000000f0,0x00);
writel_dp(0x000000f4,0x40);
writel_dp(0x000000f8,0x0c);
writel_dp(0x000000fc,0x83);
writel_dp(0x00000100,0x06);
writel_dp(0x00000104,0x20);
writel_dp(0x00000108,0xb8);
writel_dp(0x0000010c,0x00);
writel_dp(0x00000110,0x46);
writel_dp(0x00000114,0x24);
writel_dp(0x00000118,0xff);
writel_dp(0x0000011c,0x00);
writel_dp(0x00000120,0x44);
writel_dp(0x00000124,0xfa);
writel_dp(0x00000128,0x08);
writel_dp(0x0000012c,0x00);
writel_dp(0x00000130,0x01);
writel_dp(0x00000134,0x64);
writel_dp(0x00000138,0x14);
writel_dp(0x0000013c,0x00);
writel_dp(0x00000140,0x00);
writel_dp(0x00000150,0x1c);
writel_dp(0x00000160,0x1c);
writel_dp(0x00000164,0x11);
writel_dp(0x0000016c,0x30);
writel_dp(0x00000170,0x25);
writel_dp(0x00000174,0x14);
writel_dp(0x00000178,0x0e);
writel_dp(0x0000017c,0x01);
writel_dp(0x0000018c,0x01);
writel_dp(0x00000190,0x0e);
writel_dp(0x000001a0,0x00);
writel_dp(0x000001a4,0x02);
writel_dp(0x000001ac,0x00);
writel_dp(0x000001bc,0x00);
writel_dp(0x000001cc,0x02);
writel_dp(0x000001d0,0x00);
writel_dp(0x000001d4,0x20);
writel_dp(0x000001d8,0x30);
writel_dp(0x000001dc,0x08);
writel_dp(0x000001e0,0x0c);
writel_dp(0x000001e8,0x00);
writel_dp(0x000001ec,0x00);
writel_dp(0x000001f0,0x00);
writel_dp(0x000001f4,0x00);
writel_dp(0x000001f8,0x00);
writel_dp(0x000001fc,0x00);
writel_dp(0x00000200,0x00);
writel_dp(0x00000228,0x55);
writel_dp(0x0000022c,0x25);
writel_dp(0x00000230,0x2c);
writel_dp(0x00000234,0x22);
writel_dp(0x00000238,0x14);
writel_dp(0x0000023c,0x20);
writel_dp(0x00000240,0x00);
writel_dp(0x00000244,0x00);
writel_dp(0x00000248,0x00);
writel_dp(0x0000024c,0x00);
writel_dp(0x00000268,0x10);
writel_dp(0x00000450,0x00);
writel_dp(0x00000454,0x00);
writel_dp(0x00000458,0x00);
writel_dp(0x0000045c,0x00);
writel_dp(0x00000c7c,0x15);
writel_dp(0x00000c80,0xa0);
writel_dp(0x0000107c,0x15);
writel_dp(0x00001080,0xa0);
writel_dp(0x0000147c,0x15);
writel_dp(0x00001480,0xa0);
writel_dp(0x0000187c,0x15);
writel_dp(0x00001880,0xa0);
writel_dp(0x000000f0,0x80);
writel_dp(0x00000204,0x01);
writel_dp(0x00000208,0x04);
writel_dp(0x0000020c,0x24);
writel_dp(0x00000210,0x20);
writel_dp(0x00000214,0x03);
writel_dp(0x0000021c,0x04);
writel_dp(0x00000224,0x00);
writel_dp(0x00000254,0x03);
writel_dp(0x0000025c,0x00);
writel_dp(0x00000264,0x00);
writel_dp(0x00000268,0x11);
writel_dp(0x0000026c,0x00);
writel_dp(0x00000800,0x00);
writel_dp(0x00000818,0x07);
writel_dp(0x0000081c,0x0f);
writel_dp(0x00000c0c,0x0c);
writel_dp(0x00000c1c,0x60);
writel_dp(0x00000c28,0x17);
writel_dp(0x00000c2c,0x77);
writel_dp(0x00000c30,0x77);
writel_dp(0x00000c34,0x77);
writel_dp(0x00000c38,0x38);
writel_dp(0x00000c40,0x03);
writel_dp(0x00000c44,0x0f);
writel_dp(0x00000c58,0x02);
writel_dp(0x00000c6c,0x01);
writel_dp(0x0000100c,0x0c);
writel_dp(0x0000101c,0x60);
writel_dp(0x00001028,0x17);
writel_dp(0x0000102c,0x77);
writel_dp(0x00001030,0x77);
writel_dp(0x00001034,0x77);
writel_dp(0x00001038,0x38);
writel_dp(0x00001040,0x03);
writel_dp(0x00001044,0x0f);
writel_dp(0x00001058,0x02);
writel_dp(0x0000106c,0x01);
writel_dp(0x0000140c,0x0c);
writel_dp(0x0000141c,0x60);
writel_dp(0x00001428,0x17);
writel_dp(0x0000142c,0x77);
writel_dp(0x00001430,0x77);
writel_dp(0x00001434,0x77);
writel_dp(0x00001438,0x38);
writel_dp(0x00001440,0x03);
writel_dp(0x00001444,0x0f);
writel_dp(0x00001458,0x02);
writel_dp(0x0000146c,0x01);
writel_dp(0x0000180c,0x0c);
writel_dp(0x0000181c,0x60);
writel_dp(0x00001828,0x17);
writel_dp(0x0000182c,0x77);
writel_dp(0x00001830,0x77);
writel_dp(0x00001834,0x77);
writel_dp(0x00001838,0x38);
writel_dp(0x00001840,0x03);
writel_dp(0x00001844,0x0f);
writel_dp(0x00001858,0x02);
writel_dp(0x0000186c,0x01);
writel_dp(0x00000278,0x03);
writel_dp(0x0000027c,0xea);
writel_dp(0x00000280,0x40);
udelay(10);
writel_dp(0x0000027c,0xee);
udelay(10);
writel_dp(0x00000280,0x60);
udelay(10);
writel_dp(0x0000027c,0xfe);
udelay(120);
writel_dp(0x0000027c,0xff);
}



int do_dbg_mmio(char *cmd[], unsigned int param_count)
{
	unsigned int reg_index;
	unsigned int reg_data;
	unsigned int reg_start;
	unsigned int read_num;
	unsigned int line_index;
	int i;

	if (param_count == 2) // two parameters. register read.
	{
		if ((strcmp(cmd[1], "-d") != 0)&&(strcmp(cmd[1], "-dp") != 0)){  //for argv =2 && not reag rigister;
		reg_index = StoH(cmd[1]);
		reg_data = readl(video_pci_prop.mapped_mmioBase + reg_index);
		printf("\nRead MMIO %x = 0x%08x\n", reg_index, reg_data);
	    }	
	    //for 3588 register dump,write death;
		else if (strcmp(cmd[1], "-d") == 0)
		{
			//dump 0x000-0x29c
			printf("\nregister 0x000-0x29c\n");
			reg_start = 0x000;
			printf("         00              04             08             0c        \n");
			for (i = 0; i <= 0xA7; i++)
			{
				if((i * 4)%0x10==0x00){
                    printf("%04x   ",i*4);
				}
				reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
				printf("  0x%08x  ", reg_data);
				if((i+1)%4==0x00){
					printf("\n");
				}
			}
			//dump 0x400-0x4a4
			printf("\nregister 0x400-0x4a4\n");
			reg_start = 0x400;
			printf("         00              04             08             0c        \n");
			for (i = 0; i <= 0x29; i++)
			{
				if((i * 4)%0x10==0x00){
                    printf("%04x   ",(0x400+i*4));
				}
				reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
				printf("  0x%08x  ", reg_data);
				if((i+1)%4==0x00){
					printf("\n");
				}
			}
			//dump 0x400-0x4a4
			printf("\nregister 0x800-0x8a4\n");
			reg_start = 0x800;
			printf("         00              04             08             0c        \n");
			for (i = 0; i <= 0x29; i++)
			{
				if((i * 4)%0x10==0x00){
                    printf("%04x   ",(0x800+i*4));
				}
				reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
				printf("  0x%08x  ", reg_data);
				if((i+1)%4==0x00){
					printf("\n");
				}
			}
			printf("\nregister 0xc00-0xcb4\n");
			reg_start = 0xc00;
			printf("         00              04             08             0c        \n");
			for (i = 0; i <= 0x2D; i++)
			{
				if((i * 4)%0x10==0x00){
                    printf("%04x   ",(0xC00+i*4));
				}
				reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
				printf("  0x%08x  ", reg_data);
				if((i+1)%4==0x00){
					printf("\n");
				}
			}
			printf("\nregister 0x1000-0x10b4\n");
			reg_start = 0x1000;
			printf("         00              04             08             0c        \n");
			for (i = 0; i <= 0x2D; i++)
			{
				if((i * 4)%0x10==0x00){
                    printf("%04x   ",(0x1000+i*4));
				}
				reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
				printf("  0x%08x  ", reg_data);
				if((i+1)%4==0x00){
					printf("\n");
				}
			}
			printf("\nregister 0x1400-0x14b4\n");
			reg_start = 0x1400;
			printf("         00              04             08             0c        \n");
			for (i = 0; i <= 0x2D; i++)
			{
				if((i * 4)%0x10==0x00){
                    printf("%04x   ",(0x1400+i*4));
				}
				reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
				printf("  0x%08x  ", reg_data);
				if((i+1)%4==0x00){
					printf("\n");
				}
			}
			printf("\nregister 0x1800-0x18b4\n");
			reg_start = 0x1800;
			printf("         00              04             08             0c        \n");
			for (i = 0; i <= 0x2D; i++)
			{
				if((i * 4)%0x10==0x00){
                    printf("%04x   ",(0x1800+i*4));
				}
				reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
				printf("  0x%08x  ", reg_data);
				if((i+1)%4==0x00){
					printf("\n");
				}
			}	
		}
		else if (strcmp(cmd[1], "-dp") == 0){
			do_mm_write_DP8();  
		}
	}
	else if (param_count == 3) // register write
	{
		reg_index = StoH(cmd[1]);
		reg_data = StoH(cmd[2]);
		writel(reg_data, video_pci_prop.mapped_mmioBase + reg_index);
		printf("\nWrite MMIO %x = 0x%08x Done.\n", reg_index, reg_data);
	}
	else if (param_count >= 4)
	{
		// ADD MORE REGISTER READ; non-sequence
		if (strcmp(cmd[1], "-m") == 0)
		{
			for (i = 2; i < param_count; i++)
			{
				reg_index = StoH(cmd[i]);
				reg_data = readl(video_pci_prop.mapped_mmioBase + reg_index);
				printf("\nRead MMIO %x = 0x%08x\n", reg_index, reg_data);
			}
		}
		else if (strcmp(cmd[1], "-b") == 0)
		{
				reg_start = StoH(cmd[2]);
				read_num = StoH(cmd[3]);			
				for (i = 0; i < read_num; i++)
				{
					reg_data = readb(video_pci_prop.mapped_mmioBase + reg_start + i);
					printf("\nRead MMIO %x = 0x%02x\n", (reg_start + i), reg_data);
				}
			
		}
		// ADD -W DWORE;sequence
		else if (strcmp(cmd[1], "-w") == 0)
		{
			
				reg_start = StoH(cmd[2]);
				read_num = StoH(cmd[3]);
				for (i = 0; i < read_num; i++)
				{
					reg_data = readl(video_pci_prop.mapped_mmioBase + reg_start + i * 4);
					printf("\nRead MMIO %x = 0x%08x\n", (reg_start + i * 4), reg_data);
				}
			
		}	
	}
	else
	{
		// printf("\nParse Error!\n");
		mmio_help_info();
	}


return TRUE;
}

void mmio_help_info(void)
{
	printf("  mmio -m register1 register2 register3...: non-sequence register read.\n");
	printf("  mmio -b addr num: sequence register read byte.\n");
	printf("  mmio -w addr num: sequence register read dword\n");
	printf("  mmio register: register read dword\n");
	printf("  mmio register [data]: register write dword\n");
	// printf("  clk -f/F e/E data(MHz)]:change eclk and print eclk and vclk.\n");
}

int do_dbg_ts(char *cmd[], unsigned int param_count)
{
	printf("Temp : %d C\n", dout_to_temp(GetTemperature()) / 1000);
	return TRUE;
}

int do_dbg_voltage(char *cmd[], unsigned int param_count)
{
	printf("voltage : %d mV\n", (GetVoltage() * 1000 + 1157200) / 1869);
	return TRUE;
}

int do_dbg_print_info(char *cmd[], unsigned int param_count)
{
	if (video_pci_prop.VenderId == 0x6766 && video_pci_prop.DeviceId == 0x3d02)
	{

		printf("Technology : 28 nm\n");
		printf("Die Size : 322 mm*mm\n");
		printf("Transistors : 445 M\n");
		printf("ROPS/TMUS : 16/32\n");
		printf("Shaders : 256 Unified\n");
		printf("DirectX Support : 11.0\n");
	}
	if (video_pci_prop.VenderId == 0x6766 && video_pci_prop.DeviceId == 0x3d00)
	{

		printf("Technology : 28 nm\n");
		printf("Die Size : 322 mm*mm\n");
		printf("Transistors : 445 M\n");
		printf("ROPS/TMUS : 96/192\n");
		printf("Shaders : 1536 Unified\n");
		printf("DirectX Support : 11.0\n");
	}
	ts_init();
	sf_init();
	read_fw_version();
	read_PCIe();
	printf("DDR Version : DDR4\n");
	read_bitwidth();
	printf("Memory Clk : %d MHz\n", get_mpll());
	printf("Elite Clk : %d MHz\n", get_vepll(EPLL_REG));
	printf("VIDEO Clk : %d MHz\n", get_vepll(VPLL_REG));
	printf("Temp : %d C\n", dout_to_temp(GetTemperature()) / 1000);
	printf("voltage : %d mV\n", (GetVoltage() * 1000 + 1157200) / 1869);
	printf("FAN1 Speed:%d RPM\n", get_fs_speed(1));
	return true;
}

int do_dbg_flash(char *cmd[], unsigned int param_count)
{
	sf_init();
	sf_flash_test(param_count, cmd);
	return TRUE;
}

int do_dbg_mem_test(char *cmd[], unsigned int param_count)
{
	chip_mem_connection_test(param_count, cmd);
	return TRUE;
}

int do_dbg_i2c_test(char *cmd[], unsigned int param_count)
{
	i2c_prog(param_count, cmd);
	return TRUE;
}
int do_dbg_efuse_test(char *cmd[], unsigned int param_count)
{
	// helpinfo();
	efuse_test(param_count, cmd);
	return TRUE;
}
int do_dbg_dp_test(char *cmd[], unsigned int param_count)
{
	chip_mem_connection_test(param_count, cmd);
	return TRUE;
}
int do_dbg_cts_test(char *cmd[], unsigned int param_count)
{
	cts_test(param_count, cmd);
	return TRUE;
}

int do_dbg_program_fw(char *cmd[], unsigned int param_count)
{
	sf_init();
	if (param_count >= 2)
	{
		flash_vbios(cmd[1]);
	}
	else
	{
		printf("  prog filename: program spi flash.\n");
	}
	return TRUE;
}

int do_dbg_dump_fw(char *cmd[], unsigned int param_count)
{
	unsigned int dump_file_size = MAX_VIDEO_ROM_SIZE;
    sf_init();
	if (param_count >= 2)
	{
		if (param_count == 3)
		{
			dump_file_size = atoi(cmd[2]);
		}
		else if (param_count == 2)
		{
			// read file size from vbios
			dump_file_size = sf_read_data(FW_FILE_SIZE_OFFSET, FW_FILE_SIZE_LEN);
			if (dump_file_size == 0)
			{
				dump_file_size = MAX_VIDEO_ROM_SIZE;
				printf("Use default file size! ");
			}
			else
			{
				printf("Read file size from spi flash! ");
			}
		}

		printf("Dump file size = %d\n", dump_file_size);
		dump_vbios(cmd[1], dump_file_size);
	}
	else
	{
		printf("  dump filename [filesize(byte)]: dump spi flash file.\n");
	}
	return TRUE;
}

int do_dbg_clk(char *cmd[], unsigned int param_count)
{
	clk_prog(param_count, cmd);
	return TRUE;
}

int do_dbg_help(char *cmd[], unsigned int param_count)
{
	helpinfo();
	return TRUE;
}

int do_dbg_quit(char *cmd[], unsigned int param_count)
{
	return FALSE;
}

void helpinfo(void)
{
	printf("  help/?     --- print help info\n");
	printf("  q          --- quit\n");
	printf("  ts         --- print temperature\n");
	printf("  vcore      --- print vcore\n");
	printf("  clk        --- read/write clock\n");
	printf("  memtest    --- miu test connection\n");
	printf("  sf         --- flash read and write\n");
	printf("  prog       --- program rom to flash\n");
	printf("  dump       --- dump data from flash saved to file\n");
	printf("  mmio       --- read/write register; -m read more registers\n");
	printf("  i2c        --- i2c read/write data\n");
	printf("  print      --- print all information(pcie info/mem info/vcore/clk/temp/fs)\n");
	printf("  efuse      --- efuse hdcp key1.4/2.2 function\n");
	printf("  ct         --- only for linux; need uma and test graphics card\n");
}

char GetKey(void)
{
	char key;
	/*#ifdef __dos__
		key = getch();
	#endif
	#ifdef __ubuntu__*/
	key = getchar();
	//#endif
	// if (key == 0)
	//	key = (0x80 | getch());
	return key;
}
