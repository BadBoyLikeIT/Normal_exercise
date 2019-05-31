declare @i int             --声明变量
set @i = 1                 --设置变量初始值为1
while(@i < 10000000)       --循环的范围
begin                      --开始循环
insert into dbo.test211 values(@i,GETDATE())    --插入数据语句；getdate()获取当前系统时间
waitfor delay'00:00:01'                         --插入数据后等1秒                    
set @i = @i + 1                                 --每插入一次变量加1
end                                             --结束循环