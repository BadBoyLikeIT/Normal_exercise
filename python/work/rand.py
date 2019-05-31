# 几个人
candidate_count = 6
import random
# [start, end]
def lucky(start, end, count, seed):
    rank = []
    for i in range(start, end+1):
        rank.append(i)
    random.seed(seed)
    random.shuffle(rank)
    return random.sample(rank, count)

# 记录中奖的
lucky_rank = []
# 随机种子每个人告诉我一个数字 我累加起来然后随机
# 
seed = 12+520+97+5+121+17

# 只抽3个
lucky_rank = lucky(1, candidate_count, 3, seed)

lucky_rank.sort()
print (lucky_rank)