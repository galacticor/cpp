

# function [R,bt1,bt2] = Myhouse(A,b)
#   [m,n] = size(A);
#   % satukan A dan b agar lebih mudah dilakukan operasi
#   C = [A b];
#   for j=1:n
#     % mencari nilai v dari rumus pada slide, gunakan sign untuk mengetahui tanda +/-
#     v = C(j:m,j)+sign(C(j,j))*norm(C(j:m,j))*[1;zeros(m-j,1)];
#     for i=j:n+1 % looping dari j sekarang sampai n+1, kolom n+1 adalah vektor b
#       % update setiap value dari row j kolom j sampai kolom n+1 termasuk vektor b
#       C(j:m,i)=C(j:m,i)-(2*v'*C(j:m,i)/(v'*v))*v;
#     endfor
#   endfor
#   R = C(1:n,1:n);
#   bt1 = C(1:n,n+1);
#   bt2 = C(n+1:m,n+1);

def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

import numpy

t = get_number()
while t > 0:
    t -= 1
    c = get_number()
    h = get_number()
    o = get_number()

    

