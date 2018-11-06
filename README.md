# Brainf*ck
- [wiki](https://ja.wikipedia.org/wiki/Brainfuck)
>>>
- Brainfuckプログラムは、以下の8個の実行可能な命令から成る（他の文字は無視され、読み飛ばされる）。
```
> ポインタをインクリメントする。ポインタをptrとすると、C言語の「ptr++;」に相当する。
< ポインタをデクリメントする。C言語の「ptr--;」に相当。
+ ポインタが指す値をインクリメントする。C言語の「(*ptr)++;」に相当。
- ポインタが指す値をデクリメントする。C言語の「(*ptr)--;」に相当。
. ポインタが指す値を出力に書き出す。C言語の「putchar(*ptr);」に相当。
, 入力から1バイト読み込んで、ポインタが指す先に代入する。C言語の「*ptr=getchar();」に相当。
[ ポインタが指す値が0なら、対応する ] の直後にジャンプする。C言語の「while(*ptr){」に相当。
] ポインタが指す値が0でないなら、対応する [ （の直後）にジャンプする。C言語の「}」に相当。
```
>>>
- ex)Hello World
```
>+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.[-]>++++++++[<++
++>-]<.>+++++++++++[<+++++>-]<.>++++++++[<+++>-]<.+++.------.--------.[-]>
++++++++[<++++>-]<+.[-]++++++++++.
```
# brainfuck interpreter
- C言語で実装.
- 実行すると、Brainf*ckプログラムのソースコードを標準入力から読み取り、対応するプログラムを実行する.
# brainfuck compiler
- アセンブリで実装予定.
## 仕様（目標）
- powerpc64le-linux-gnu アーキテクチャのOS上で実行できるELFバイナリである.
- 実行ファイルの大きさは1.5KiB以下.
- 実行すると、Brainf*ckプログラムのソースコードを標準入力から読み取り、標準出力にコンパイル結果を出力する.
- コンパイル後のプログラムも、同アーキテクチャのOS上で実行できるELFバイナリで、Brainf*ckの仕様通りに動作する.
- 呼び出し規約などのABIを全て守ってはいない。
