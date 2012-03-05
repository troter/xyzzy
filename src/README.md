簡単なビルド方法
================

Visual C++ 2010 をインストールしてください。

 - Visual Studio のエディションは Express でも Professional でも良いです

以下の URL から、最新のコードの zip ファイルをダウンロードしてください

 - https://github.com/mumurik/xyzzy/zipball/master

zip ファイルを展開すると、src というディレクトリがあるので、
コマンドライン上で、そこまで移動してください

    > cd ＜mumurik-xyzzy-ほにゃらら\src＞

この状態で、以下のコマンドを実行すると、リリース版のビルドが行えます

    > call "%VS100COMNTOOLS%..\..\VC\vcvarsall.bat"
    > nmake

デバッグ版をビルドする場合は、以下のコマンドを実行してください

    > nmake CFG=d

リリース版、デバッグ版をそれぞれ nmake でビルドした後は、
1 つ上のディレクトリにある xyzzy.sln を使って、Visual Studio IDE での作業が可能になります

    > start ..\xyzzy.sln


GitHub を使った開発方法
=======================

マルチフレーム版 xyzzy はバージョン管理システムとして Git (ぎっと) を用いた開発をしています。

また、ホスティングサービスとして GitHub (ぎっとはぶ) を使用しており、
メールアドレスとパスワードのみの、簡単なアカウント登録を行うだけで、直接開発への参加が可能です。


## 目標

 - GitHub でのマルチフレーム版 xyzzy の開発に参加できる環境を作ります


## GitHub で操作をする前に

 - GitHub での操作が、他の人に対して悪影響を与えることはありません
 - ローカルでの git のコマンドが、他の人に対して悪影響を与えることもありません

安心して試行錯誤しましょう :-)


## 必要なもの

 - [Visual C++ 2010 Express](http://www.microsoft.com/japan/msdn/vstudio/express/)
   - Professional 等の上位版でも良いです
 - [TortoiseGit](http://code.google.com/p/tortoisegit/downloads/list) (とーたすぎっと)
 - [MSysGit](http://code.google.com/p/msysgit/downloads/list)  (えむしすぎっと)

上記のツール類は、デフォルト設定のままインストールしてください。


## GitHub のアカウントを作る

 - [GitHub](http://github.com/) へ行き、アカウントを作成してください


## OpenSSH の鍵を作り、公開鍵を GitHub に登録する

MSysGit をインストールすることによって追加された、Git GUI を実行し、鍵を作ります

 - 「スタート」＞「Git」＞「Git GUI」を実行
 - Git GUI の「ヘルプ」＞「SSH キーを表示」を選択
   - 「キーがありません」と表示されたなら
     - 右側にある「鍵を生成」を押す
     - 「Enter passphrase」というダイアログが出るので、空欄のまま「OK」を押す
     - 「Enter same passphrase again」というダイアログが出るので、空欄のまま「OK」を押す
     - 「あなたの鍵は … にあります」という表示に変わる
     - 左下にある「クリップボードにコピー」を押す
   - 「公開鍵がありました : …」と表示されたなら
     - 左下にある「クリップボードにコピー」を押す

Git GUI はそのままにして、ブラウザを開き、GitHub に公開鍵を登録します

 - https://github.com/settings/ssh を開く
   - 開いたら、右上に自分の GitHub でのユーザ名が出ているのを確認する
 - 「Add New SSH Key」というボタンを押す
 - Git GUI からコピーしたテキスト全体を「Key」欄にペーストする。「Title」は空のままにしておく
 - 「Add key」を押す
   - 押した結果、「SSH Keys」に自分の「コンピュータ名」が追加される

Git GUI での作業は完了したので、閉じましょう。


## マルチフレーム版 xyzzy のリポジトリを Fork する

マルチフレーム版 xyzzy のリポジトリを、GitHub 上の自分のアカウントに Fork (履歴情報付きのコピー) します

 - https://github.com/mumurik/xyzzy を開く
   - 開いたら、右上に自分のGitHubでのユーザ名が出ているのを確認する
   - 画面の右上にある「`Fork`」を押す
 - Fork が実行され、`https://github.com/ＧｉｔＨｕｂでのユーザ名/xyzzy` という新しいURLに自動的に移動する
   - 「`mirror of https://bitbucket.org/mumurik/xyzzy`」と書かれている下にある「`SSH`」というボタンを押す
   - 「`SSH`」の右のほうにあるエディットボックスの内容「`git@github.com:ＧｉｔＨｕｂでのユーザ名/xyzzy.git`」という文字列をコピーして、どこかに置いておく


## ローカルにファイルを持ってくる

「スタート」＞「Git」＞「Git Bash」を実行して Git Bash を立ち上げ、
以下のコマンドを実行してください

    $ mkdir /c/github
    $ cd /c/github
    $ git clone git@github.com:ＧｉｔＨｕｂでのユーザ名/xyzzy.git
    Cloning into xyzzy...
    remote: Counting objects: XXXX, done.
    remote: Compressing objects: 100% (XXXX/XXXX), done.
    
    Receiving objects: 100% (XXXX/XXXX), X.XX MiB | XXX KiB/s, done.
    Resolving deltas: 100% (XXXX/XXXX), done.

以上で、GitHub 上にあるリポジトリの内容が、ローカルにコピーされました。

初期設定として、ユーザ名、メールアドレス、Fork 元のリポジトリを設定します

    $ cd /c/github/xyzzy
    $ git config user.name "ＧｉｔＨｕｂでのユーザ名"
    $ git config user.email "ＧｉｔＨｕｂに登録したメールアドレス"
    $ git remote add upstream https://github.com/mumurik/xyzzy.git
    $ git fetch upstream


## ビルドする

cmd.exe を開き、以下を実行すると、リリース版がビルドされます

    > cd C:\github\xyzzy\src
    > call "%VS100COMNTOOLS%..\..\VC\vcvarsall.bat"
    > nmake

以下を実行すると、デバッグ版がビルドされます

    > nmake CFG=d

リリース版、デバッグ版をそれぞれ nmake でビルドした後は、
1 つ上のディレクトリにある xyzzy.sln を使って作業が可能になります

    > start C:\github\xyzzy\xyzzy.sln


## 編集、commit、push する

- TODO : master で作業する是非について、何か書く？

変更したい点がある場合、以下のように作業を行いましょう

 - C:\github\xyzzy\ 下にあるファイルを編集する
 - ビルド、テスト等を行う
 - 変更点をリポジトリに登録するには、git commit を実行する
   - git commit をするには、エクスプローラ等で xyzzy フォルダを右クリックし、「Git Commit」を実行してください
   - コマンドラインから git commit をする場合は Git Bash 上で以下のようなコマンドを入力します

            $ cd /c/github/xyzzy
            $ git commit -m 'コミットメッセージ'

 - 最初に戻って作業を繰り返す

ある程度作業がまとまったら、
GitHub サーバにある自分のリポジトリにアップロードしましょう。
アップロードには git push というコマンドを使用します

    $ cd /c/github/xyzzy
    $ git push origin master

あなたが作業している間に、Fork 元のコードが更新されているかもしれません。
更新に追いつきたい場合は以下のコマンドを実行します

    $ cd /c/github/xyzzy
    $ git stash
    $ git fetch upstream
    $ git checkout master
    $ git rebase upstream/master
    $ git stash pop

以上の操作を繰り返して、作業を行います。


## Pull Request で変更点を作者に提案する

GitHub サーバにあなたのコードがある場合、
マルチフレーム版 xyzzy の作者に対して、変更点の提案を行うことができます。

提案の前に、以下の点を確認しましょう

 - 動作する状態で、提案する
 - 一度にたくさんの提案をするのは避ける

変更点の提案を送信するには、GitHub の Pull Request という機能を使用します

 - 自分のリポジトリが見える URL `https://github.com/ＧｉｔＨｕｂでのユーザ名/xyzzy` に移動する
 - 右上にある「Pull Request」というボタンを押す
 - どのような変更を提案したいのか、フォームに書き入れる
 - 右下にある緑色の「Send pull request」ボタンを押す

Pull Request が送信されました。
しばらくすると、GitHubに登録したメールアドレスや、
[ダッシュボード](https://github.com/)に返答が来るはずです。

- TODO : Pull Request した後にはどういう操作をすべきか？


## チートシート

 - TODO : ちゃんとした説明を書く
 - TODO : ちゃんとした運用方法を書く
 - TODO : TortoiseGit の簡単な使い方
 - TODO : Pull Request の送り方
 - TODO : Spoon-Knife

「スタート」＞「Git」＞「Git Bash」を実行して Git Bash を立ち上げ、
以下のコマンドを実行することで、さまざまな作業を行えます

 - 間違ったので、直前の commit を取り消したい

        $ git reset --hard HEAD^

 - ローカルの master を upstream に合わせる

        $ cd /c/github/xyzzy
        $ git stash
        $ git fetch upstream
        $ git checkout master
        $ git rebase upstream/master
        $ git stash pop

 - ローカルの master を GitHub に push する

        $ cd /c/github/xyzzy
        $ git push origin master

 - ブランチを作る

        $ cd /c/github/xyzzy
        $ git checkout -b ブランチ名

 - ローカルのブランチと master を upstream に合わせる

        $ cd /c/github/xyzzy
        $ git stash
        $ git fetch upstream
        $ git checkout master
        $ git rebase upstream/master
        $ git checkout ブランチ名
        $ git rebase master
        $ git stash pop

 - ローカルのブランチを GitHub に push する

        $ cd /c/github/xyzzy
        $ git push -f origin ブランチ名

 - Pull Request 用に、コミットを 1 つにまとめて GitHub に push する

        $ cd /c/github/xyzzy
        $ git checkout ブランチ名
        $ git checkout まとめブランチ名
        $ git rebase -i master
        $ git push origin まとめブランチ名

 - ローカルのブランチを消す

        $ cd /c/github/xyzzy
        $ git checkout master
        $ git branch -d ブランチ名

 - GitHub にあるブランチを消す

        $ git push origin :ブランチ名
