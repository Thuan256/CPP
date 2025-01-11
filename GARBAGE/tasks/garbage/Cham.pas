program cham;
uses    crt;
const   ff='GARBAGE';
        KQ:array[0..9] of longint = (544,3711,30954,53587,51689,123271499,
                                     258037514,475018067,742035929,822984735);
var     diem:array[0..9] of real;
        loi:array[0..9] of integer;
        A:array[1..1000,1..1000] of longint;
        M,N:integer;
        ft,fi:text;
procedure doc(s:string);
var     i,j:integer;
begin
        readln(fi,M,N);
        for i:=1 to M do
        Begin
                for j:=1 to N do read(fi,A[i,j]);
                readln(fi);
        end;
end;
procedure cham(p:integer);
var     i,j:integer;
        KQt:longint;
        ok:boolean;
begin
        readln(ft,KQt);
        loi[p] := 0;
        if KQt <> KQ[p] then
        Begin
                loi[p] := 1;
                diem[p] := 0;
                exit;
        end;
        diem[p] := 0.5;
        KQt := 0;
        for i:=1 to M do
        Begin
                readln(ft,j);
                KQt := KQt + A[i,j];
        end;
        if KQt <> KQ[p] then
        Begin
                loi[p] := 2;
                exit;
        end;
        diem[p] := 1;
end;
procedure xuly;
var     i,p:integer;
        st,si:string;
Begin
        for p:=0 to 9 do
        Begin
                si := ff + chr(p + 48) + '.in';
                st := ff + chr(p + 48) + '.ou';
                assign(fi,si); reset(fi);
                assign(ft,st); reset(ft);
                doc(si);
                cham(p);
                close(fi);
                close(ft);
        end;
end;
procedure Inkq;
var     i:integer;
        t:real;
Begin
        clrscr;
        Writeln;
        writeln;
        writeln('     ******************************************************');
        writeln('                      Ket qua cham '                        );
        writeln('     ******************************************************');
        writeln;
        t:= 0;
        for i:=0 to 9 do
        Begin
                t := t + diem[i];
                write('          test ',i,':', diem[i]:3:1);
                case    loi[i]   of
                0: writeln(' Dung');
                1: writeln(' Sai ket qua');
                2: writeln(' Sai truy vet');
                end;
        end;
        writeln;
        writeln('     ******************************************************');
        writeln;
        writeln('             tong diem:', T:3:1);
end;
Begin
        xuly;
        inkq;
end.
