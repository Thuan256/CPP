with open("COMPUTER.inp","r") as f:
    a1,a2,a3=map(int,f.readline().split())
    b1,b2,b3=map(int,f.readline().split())
    f.close()
vga=min(a1,b1)
a1-=vga
b1-=vga
dvi=min(a2,b2)
a2-=dvi
b2-=dvi
du_vga=min(a3,b1)
a3-=du_vga
b1-=du_vga
du_dvi=min(a3,b2)
a3-=du_dvi
b2-=du_dvi
vga_du=min(b3,a1)
b3-=vga_du
a1-=vga_du
dvi_du=min(b3,a2)
b3-=dvi_du
a2-=dvi_du
du=min(a3,b3)
tong=vga+dvi+du_vga+du_dvi+vga_du+dvi_du+du
with open("COMPUTER.out","w") as f:
    f.write(str(tong))
    f.close()