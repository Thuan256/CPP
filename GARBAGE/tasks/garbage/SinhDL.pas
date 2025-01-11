program sinhdl;
uses    crt;
const   fi='GARBAGE';
        N:array[0..9] of integer = (10,20,30,40,50,600,700,800,900,1000);
        M:array[0..9] of integer = (8,15,35,40,35,500,670,850,1000,1000);
var     f:text;
procedure sinh;
var     i,j,p:integer;
        s:string;
Begin
        for p:=0 to 9 do
        Begin
                s := fi + chr(p + 48) + '.in';
                assign(f,s); rewrite(f);
                writeln(f,M[p],' ',N[p]);
                for i:=1 to M[p] do
                Begin
                        for j:=1 to N[p] do write(f,random(M[p]*N[p]+1),' ');
                        writeln(f);
                end;
                close(f);
        end;
end;
begin
        sinh;
end.