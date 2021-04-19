// #include <chronos.h>
// int refilltimehour = 4;
// int refilltimeminute = 30;
// int refilltimedays = 4;
// chronos::datetime lastrefill;
// chronos::datetime lastoncircularion;
// chronos::datetime lastrefill;
// 
// void checkactions()
// {
//     chronos::datetime nowtime(chronos::datetime::now());
//     chronos::span::absolute diff = lastrefill - nowtime;
// 
//     if(diff.days() >= refilltimedays 
//         && nowtime.hour() >= refilltimehour  
//         && minute.minute() >= refilltimeminute)
//     {
//         totaltankrefill();
//         chronos::datetime lastrefilldate(nowtime.year(), nowtime.month(), nowtime.day(), 0, 0, 0);
//         lastrefill = lastrefilldate;
//     }
// }