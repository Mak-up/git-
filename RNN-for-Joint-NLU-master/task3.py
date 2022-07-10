# 使用numpy实现两层神经网络
#一个全连接的Relu神经网络，一个隐藏层，没有bias，用来从x预测y:

import numpy as np

#神经网络参数定义：
N,D_in,D_out,H=64,1000,10,100
# N：代表64个样本
# D_in:代表每个样本输入到神经网络1000个数据点
# D_out:代表每个样本从神经网络输出10个数据点
# H:代表该神经网络隐藏层维度为100

#np.random.randn()随机生成0到一的数（左闭右开）
x=np.random.randn(N,D_in)
#定义输入到神经网络之前的数据矩阵，大小为64*1000
y=np.random.randn(N,D_out)
#定义从神经网络输出的的数据矩阵，大小为64*10
w_1=np.random.randn(D_in,H)
#1000*100
w_2=np.random.randn(H,D_out)
#100*10

#定义学习率 learning rate
learning_rate=1e-06
for times in range(500):
    #forword pass
    h=x.dot(w_1)
    #64*100
    # numpy中的点乘np.dot是数学意义上的向量内积
    h_relu=np.maximum(h,0)
    #将h逐位与0比较
    y_hat=h_relu.dot(w_2)
    #64*10

    #计算损失
    loss=np.square(y_hat-y).sum()
    #估计值与真实值之间差值的平方和再取和
    print(times,loss)

    #计算梯度，主要是对(y_hat-y)^2求各项偏导
    y_hat_grad=2*(y_hat-y)
    w_2_grad=h_relu.T.dot(y_hat_grad)
    #100*64
    h_relu_grad=y_hat_grad.dot(w_2.T)
    h_grad=h_relu_grad.copy()
    h_grad[h<0]=0
    w_1_grad=x.T.dot(h_grad)

    #更新w_1和w_2的权值
    w_1=w_1-learning_rate*w_1_grad
    w_2=w_2-learning_rate*w_2_grad
