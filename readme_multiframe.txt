## 概要 ##

multiframe版の全部入りパッケージです。
C-x 5 2
で新しいフレームが開けます。


## 配布場所 ##

最新版は以下からダウンロード出来ます。
https://bitbucket.org/mumurik/xyzzy/downloads

githubへの乗り換え評価中。
https://github.com/mumurik/xyzzy


## セットアップ ##

配布のzipを展開してxyzzy.exeを実行するだけです。 
既存の環境に上書きする場合はxyzzy.wxpを削除してください。

また、幾つかのlispパッケージはそのままでは動かない事が分かっています。
以下を参照してください。
https://bitbucket.org/mumurik/xyzzy/wiki/%E5%8B%95%E3%81%8B%E3%81%AA%E3%81%84lisp%E3%83%91%E3%83%83%E3%82%B1%E3%83%BC%E3%82%B8%E4%B8%80%E8%A6%A7


## 更新履歴 ##

== 0.2.3.3から0.2.3.4への修正点 ==

今回は主にfix寄りでしたが、結構変更されてます。

* WoW64環境でsystem32以下のファイルが見えるように(Thanks to Part17 638氏)
* frame-hook系をemacsとより互換に
** *before-make-frame-hook*をframeが作られる前に
** *after-make-frame-hook*を*after-make-frame-functions*にリネーム
** *delete-frame-functions*を追加
** C-x 5 o other-framesの実装
* UnitTestを入れる (Thanks to bowbow99氏, southly氏）
* *scratch*<2>とかかっこ悪いのが出来てたのが直る (Thanks to tn氏）
* previous-pseudo-frameが壊れてたのをfix (Thanks to youz氏）

そのほかバグfixが幾つか。

== 0.2.3.2から0.2.3.3への修正点 ==

主にsouthly氏のgithubにある既存パッチの取り込みと、2310氏のUSB起動パッチを（変更した上で）取り込みました。
southly氏、2310氏、MIYAMUKO氏、及びスレやWikiにパッチを公開してくれた皆様に感謝。

** southly氏のgithubからの取り込み **

以下に主な物を挙げておきます。

* IMEの前後フィードバックのサポート(http://fixdap.com/p/xyzzy/7376/)
* lispのformat関数の挙動の良く分からない部分を修正
* si:putenvの追加(http://d.hatena.ne.jp/miyamuko/20100910/xyzzy_putenv)
* hashtableがrehash時にクリアしたエントリを間違ってマークしようとして落ちる問題の修正(https://github.com/southly/xyzzy.src/commit/88c011a05c0fb88864c1477f3b3d88da60cad9f3)
* tar32.dllのVer. 2.35以降から利用出来るlzma及びxzの圧縮展開に対応
* DLLプリロード攻撃に対する対応。現在のワーキングディレクトリをdllロードの検索対象から外す(https://github.com/southly/xyzzy.src/commit/1fa86d358323dd4c17abda724f675b8b686beea9, https://github.com/southly/xyzzy.src/commit/a5ac9b45d187724251c9963e71862ee447475889)

正確なリストはgithubの履歴を参照ください。https://github.com/mumurik/xyzzy/commits/master

** USB起動 **

* xyzzy.exeと同じパスにxyzzy.iniがある場合、そのiniファイルが使われるように修正
* iniファイル内でusbHomeDirとusbConfigDirを追加。この値がxyzzy.exeからの相対パスとして解釈され、homeとconfigのdirとして使われる
* archiverのdllのロード先としてxyzzy.exeと同じフォルダのlib/を追加

詳細は以下のurlで。https://bitbucket.org/mumurik/xyzzy/wiki/USB%E8%B5%B7%E5%8B%95


** southly氏のgithub **

https://github.com/southly/xyzzy.src
masterとnanri-masterを主にマージ。

** 2310氏のpatch **

http://blog.2310.net/archives/618
（xyzzy-0.2.235-2009092301.patchの内、関連部分を適用）


== 0.2.3.1から0.2.3.2への修正点 ==

* 「指定幅で折り返し」を「共通設定を保存」で保存しても保存されない（ように見える）バグを修正
* 複数フレームがある状態で複雑な切り取り、貼り付けを繰り返すと場合によっては落ちる事があるのを修正
* 現在選択中で無いバッファバーも更新されるように修正

== 0.2.2.235から0.2.3.1への修正点 ==

* 複数フレーム対応 (C-x 5 2, また関連でC-x 5 1, C-x 5 0も入っている)
* *features*に:multiple-framesを入れる
* split-window-verticallyをC-5からC-3へ
* 画面端の折り返しがウィンドウ単位でちゃんと動くように
* ghost化した時(応答がありません、ってなった時)にもC-gがちゃんと効くように
* mode-line-formatに%/を追加 (バッファの中で現在のキャレットが何%の位置にいるか、を表示）



## 変更元のバージョン ##
ベースは以下のURLのxyzzy-0.2.2.235.zipを元にしております。
http://www.jsdlab.co.jp/~kamei/




