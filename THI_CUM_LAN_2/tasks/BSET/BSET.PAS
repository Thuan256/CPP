Program BSET;
const   fi ='BSET.INP';
        fo ='BSET.OUT';
        nmax = 100000;
var     A,B:array[-1000..1000] of longint;
        dd:array[-1000..1000] of longint;
        n,m,dhop,dgiao:longint;
procedure doc;
var     f:text;
        i,x:longint;
begin
        assign(f,fi); reset(f);
        readln(f,n,m);
        for i:=1 to n do
        begin
                read(f,x);
                a[x] := 1;
        end;
        for i:=1 to m do
        begin
                read(f,x);
                b[x] := 1;
        end;
        close(f);
end;
procedure xuly;
var     i,d1,d2:longint;
begin
        dgiao := 0;
        d1 := 0;
        d2 := 0;
        for i:=-1000 to 1000 do
        begin
                if a[i] = 1 then inc(d1);
                if b[i] = 1 then inc(d2);
        end;
        n := d1;
        m := d2;
        for i:=-1000 to 1000 do
        if (a[i] = 1) and (b[i] = 1) then inc(dgiao);
        dhop := m + n - dgiao;
end;
procedure ghi;
var     f:text;
begin
        assign(f,fo); rewrite(f);
        write(f,dhop,' ',dgiao);
        close(f);
end;
BEGIN
        doc;
        xuly;
        ghi;
END.
