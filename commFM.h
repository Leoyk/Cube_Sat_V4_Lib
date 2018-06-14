#ifndef _COMMFM_H__
#define _COMMFM_H__

//初始化FM模块所需的引脚和波特率
void FMinit();

//设置频率，范围870~1080，最后一位是小数点
void setFre(int a);

//设置音量，范围0~30
void setVol(int a);

//请求状态值，应用于获取状态值之前，请求后至少80ms后才能调用获取函数
void orderState();

//获取状态值，成功返回0；失败，返回1；分别传到两个变量里，frequency为int型，当调整模块的音量或频率时获取的数据可能会失败
bool getState(int *volume,int *frequncy);





#endif