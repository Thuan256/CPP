{$MODE OBJFPC}
{$R-,Q-,S-,I+}
{$OPTIMIZATION LEVEL2}
program IntervalCover;
uses Windows, SysUtils, Math;
const
  prefix = 'garbage';
  InputFile  = prefix + '.INP';
  OutputFile = prefix + '.OUT';
  AnswerFile = prefix + '.OUT';
var
  dirT, dirC: WideString;
  fi, fo, fa: TextFile;

procedure GenErr(const s: string; const param: array of const);
begin
  raise Exception.CreateFmt(s, param);
end;

procedure ReadDirs;
var
  s: AnsiString;
begin
  ReadLn(s); dirT := Utf8Decode(s);
  ReadLn(s); dirC := Utf8Decode(s);
end;

procedure OpenFiles;
var
  CurrentDir: array[0..Max_Path + 1] of WideChar;
begin
  GetCurrentDirectoryW(Max_Path, CurrentDir);
  SetCurrentDirectoryW(PWideChar(dirT));
  AssignFile(fi, InputFile); Reset(fi);
  AssignFile(fa, AnswerFile); Reset(fa);
  SetCurrentDirectoryW(CurrentDir);
  SetCurrentDirectoryW(PWideChar(dirC));
  AssignFile(fo, OutputFile); Reset(fo);
end;

procedure CloseFiles;
begin
  CloseFile(fi);
  CloseFile(fa);
  CloseFile(fo);
end;

procedure DoCheck;
var     A:array[1..1000,1..1000] of longint;
        N,da,j,i,kq,Thetich,Giatri,M,K,S:longint;
        ok:boolean;
begin
  readln(fi,M,N);
  for i := 1 to M do
  begin
        for j := 1 to N do read(fi,A[i,j]);
        readln;
  end;
  readln(fa,da);
  readln(fo,kq);
  if da <> kq then
  Begin
        write(da,' ',kq,' sai ket qua');
        exit
  end;
  S := 0;
  for i:=1 to M do
  Begin
         readln(fo,j);
         S := S + A[i,j];
  end;
  if S <> kq then
  begin
        write(S,' ', kq, ' tong gia tri khac voi ket qua');
        exit;
  end;
  write('1.0')
end;

begin
  try
    try
      ReadDirs;
      OpenFiles;
      DoCheck;
    finally
      CloseFiles;
    end;
  except
    on E: Exception do
      begin
        WriteLn(E.Message);
        WriteLn('0.0');
      end;
  end;
end.

