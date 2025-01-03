uses    crt,sysutils;
var     k,N,i,M,x:longint;
        dd,dda,ddb:array[-1000..1000] of integer;
        a,b:array[1..100000] of longint;
        id:integer;
        ok : boolean;
BEGIN
        randomize;
        assign(output,'BSET.INP'); rewrite(output);

        id := StrToInt(ParamStr(1));
        N := random(10000) + 90001;
        M := random(10000) + 90001;
        if (id <= 5) then
        begin
                N := random(20) + 1;
                M := random(20) + 1;
        end
        else    if (id <=15) then
                Begin
                        N := random(100) + 901;
                        M := random(100) + 901;
                end;

        writeln(N,' ',M);
        for i:=1 to n do
        begin
                        if (id <=5) then a[i] := random(50)-random(50)
                        else a[i] := random(1001) - random(1001);
                dd[a[i]] := 1;
        end;
        for i:=1 to m do
        begin
                k:=random(2);
                if k = 0 then
                begin
                                if (id <=5) then b[i] := random(50)-random(50)
                                else b[i] := random(1001) - random(1001);
                end
                else    begin
                                repeat
                                        if (id <=5) then b[i] := random(50)-random(50)
                                        else b[i] := random(1001) - random(1001);
                                until (dd[b[i]] = 1);
                        end;
        end;
        for i:=1 to n do write(a[i],' ');
        writeln;
        for i:=1 to m do write(b[i],' ');
        close(output);
END.
