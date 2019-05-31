@echo off
osql -U sa -P leehandsome -d test2 -i .\insert.sql
echo success insert!
pause