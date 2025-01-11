program GARBAGE;
const   fi='GARBAGE0.IN';
        fo='GARBAGE0.OU';
        nmax = 1000;
Var     A,F:array[0..nmax+1,0..nmax+1] of int64;
        vet,kq:array[1..nmax] of integer;
        M,N:integer;
        files:text;
procedure doc;
var     i,j:integer;
begin
        assign(files,fi); reset(files);
        readln(files,M,N);
        for i:=1 to M do
        Begin
                for j:=1 to N do read(files,A[i,j]);
                readln(files);
        end;
        close(files);
end;
procedure QHD;
var     i,j:integer;
Begin
        fillchar(F,sizeof(F),0);
        for i:=1 to N do F[1,i] := A[1,i];
        for i:=2 to M do
        for j:=1 to N do
        Begin
                F[i,j] := F[i-1,j-1] + A[i,j];
                if F[i,j] < F[i-1,j] + A[i,j] then
                        F[i,j] := F[i-1,j] + A[i,j];
                if F[i,j] < F[i-1,j+1] + A[i,j] then
                        F[i,j] := F[i-1,j+1] + A[i,j];
        end;
end;
procedure truyvet(j:integer);
var     i:integer;
Begin
        i := M;
        While i > 1 do
        Begin
                if F[i,j] - A[i,j] = F[i-1,j-1] then
                Begin
                        kq[i-1] := j-1;
                        j := j-1;
                end
                else if F[i,j] - A[i,j] = F[i-1,j] then  kq[i-1] := j
                     else Begin
                                kq[i-1] := j + 1;
                                j := j + 1;
                          end;
                i := i - 1;
        end;
end;
procedure ghi;
var     i,vt:integer;
        Max:int64;
Begin
        assign(files,fo); rewrite(files);
        Max := F[M,1];
        vt := 1;
        for i:=2 to N do
        if Max < F[M,i] then
        Begin
                Max := F[M,i];
                vt := i;
        end;
        kq[M] := vt;
        Writeln(files,Max);
        truyvet(vt);
        for i:=1 to M do writeln(files,KQ[i]);
        close(files);
end;
Begin
        doc;
        QHD;
        ghi;
end.
