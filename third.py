
import json
from matplotlib import pyplot as plt
import time
s={}
with open('js.json','r+') as f:
   s=json.load(f)
timing=[]
classify=[]
d={
   "0":0,"1":0,
   "2":0,"3":0,"4":0,"5":0,"6":0,"7":0,"8":0,"9":0,"10":0,   
   }
for _ in s:
    st=s[_]["Start Timing"]
    
    st=st.split(":")
    st2=st[2].split(".")
    start_time=int(st[0])*(10**10)+int(st[1])*(10**8)+int(st2[0])*(10**6)+int(st2[1])
    et=s[_]["End Timing"]
    
    et=et.split(":")
    et2=et[2].split(".")
    end_time=int(et[0])*(10**10)+int(et[1])*(10**8)+int(et2[0])*(10**6)+int(et2[1])
    timing.append((end_time-start_time)/(10**6))
    classify.append(s[_]["classify"])
print(d["0"])
for _ in range(len(classify)):
    
    i=d[str(classify[_])]
    
    d[str(classify[_])]=i+timing[_]
with open ('js2.json','w+') as f:
    json.dump(d,f,indent=2,sort_keys=True)
keys=[]
key=[]
values=[]
for _ in d:
    keys.append(_)
    values.append(d[_])

for _ in range(len(keys)):
    key.append(_)
plt.barh(key,values)
plt.yticks(key,keys)
plt.show()
analog=[]
for _ in s:
    for i in range(len(s[_]["analog"])):
        analog.append(s[_]["analog"][i])
analogx=[]
for i in range(len(analog)):
    analogx.append(i)
fig=plt.figure()
ax=fig.add_subplot(111)
line1, =ax.plot(analogx,analog)
tt=0
while tt<(len(analog)):
    subx=[]
    suby=[]
    for i in range(50):
        try:
            subx.append(tt+i)
            suby.append(analog[tt+i])
        except:
            subx.append(tt+i)
            suby.append(0)
    tt+=50
    line1.set_xdata(subx)
    line1.set_ydata(suby)
    fig.canvas.draw()
    time.sleep(0.5)

        
    