t = int(input())
 
for _ in range(t):
    s = input()
    [l, r] = s.split('=') 
    l1=''
    l2=''
    op=''
    for i in range(1, len(l)):
        if(l[i]=='*' or l[i]=='-' or l[i]=='+'):
            op = l[i]
            l1 = l[0:i]
            l2 = l[i+1:len(l)]
            break
    #print(l1, l2, r, op)
    for d in range(10):
        if(l1.find(str(d))!=-1 or l2.find(str(d))!=-1 or r.find(str(d))!=-1):
            continue
        L1 = l1.replace('?', chr(ord('0') + d))
        L2 = l2.replace('?', chr(ord('0') + d))
        R = r.replace('?', chr(ord('0') + d))
        
        if(L1.find('-0')!=-1 or L2.find('-0')!=-1 or R.find('-0'))!=-1:
            continue
        try:
            if(len(L1)>1 and eval(L1)==0): continue
            if(len(L2)>1 and eval(L2)==0): continue
            if(len(R)>1 and eval(R)==0): continue
            if eval(L1+op+L2+"=="+R):
                print(d)
                break
        except:
            pass
    else:
        print(-1)
 
 
