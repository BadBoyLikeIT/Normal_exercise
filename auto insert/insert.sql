declare @i int             --声明变量
set @i = 100                 --设置变量初始值为1
while(@i < 110)       --循环的范�?
begin                      --开始循�?
insert into [dbo].test11 values(@i,GETDATE())    --插入数据语句；getdate()获取当前系统时间]
waitfor delay'00:00:01'                         --插入数据后等1�?                   
set @i = @i + 1                                 --每插入一次变量加1
end                                             --结束循环