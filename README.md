# so_long 

### Summary

このプロジェクトは、とても小さな2Dゲームです。その目的は、テクスチャやスプライト、その他非常に基本的なゲームプレイ要素を扱えるようにすることです。

This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements

| Program name  | so_long |
| --- | --- |
| Arguments | A map in format *.ber |
| External funcs | ・open, close, read, write, malloc, free, perror,
strerror, exit
・All functions of the math library (-lm compiler option, man man 3 math)
・ All functions of the MiniLibX
・ft_printf and any equivalent YOU coded |
| Libft authorized | Yes |

### Description

イルカが魚を食べた後、地球を脱出するという基本的な2Dゲームを作ってください。イルカ、魚、地球の代わりに、好きなキャラクター、好きな収集品、好きな場所を使用することができます。

You must create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want.

### IV. 1 Game

- プレイヤーの目的は、マップ上に存在するすべての収集物を集め、最短距離で脱出することです。
    
    The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
    
- 主人公の移動はW、A、S、Dの4つのキーで行います。
    
    The W, A, S, and D keys must be used to move the main character.
    
- 移動方向は上下左右の4方向です。
    
    The player should be able to move in these 4 directions: up, down, left, right.
    
- 壁にはぶつからないようにする。
    
    The player should not be able to move into walls.
    
- 移動のたびに、現在の移動回数がシェルに表示されること。
    
    At every move, the current number of movements must be displayed in the shell.
    
- 2Dビュー（トップダウンまたはプロファイル）を使用する必要があります。
    
    You have to use a 2D view (top-down or profile).
    
- ゲームはリアルタイムである必要はない。
    
    The game doesn’t have to be real time.
    
- イルカをテーマにした例を挙げましたが、あなたの好きな世界を作ることができます。
好きな世界を作ってください。
    
    Although the given examples show a dolphin theme, you can create the world you
    want.
    

### IV.2 Graphic management

- あなたのプログラムは画像をウィンドウに表示しなければならない。
    
    Your program has to display the image in a window.
    
- ウィンドウの管理はスムーズでなければならない（別のウィンドウに変更したり、最小化したり、など）。
    
    The management of your window must remain smooth (changing to another window, minimizing, and so forth).
    
- ESC キーを押すと、ウィンドウが閉じ、プログラムがきれいに終了すること。
    
    Pressing ESC must close the window and quit the program in a clean way.
    
- ウィンドウの枠にある十字をクリックすると、ウィンドウが閉じられ、プログラムが終了すること。
    
    Clicking on the cross on the window’s frame must close the window and quit the
    program in a clean way
    
- MiniLibXの画像の使用は必須です。
    
    The use of the images of the MiniLibX is mandatory.
    

### IV.3 Map

- マップは、「壁」「アイテム」「空き地」の3つの要素で構成されています。
    
    The map has to be constructed with 3 components: walls, collectibles, and free
    space.
    
- マップは、この5つの文字だけで構成することができます。
    
    The map can be composed of only these 5 characters:
    
    0は何もない空間。
    1は壁。
    Cは収集物。
    Eはマップの出口を表します。
    Pはプレイヤーのスタート位置です。
    以下、簡単な有効マップを示します。
    

- マップには少なくとも1つの出口、1つの収集品、1つのスタート地点が含まれていなければなりません。
    
    The map must contain at least 1 exit, 1 collectible, and 1 starting position.
    
- マップは長方形であること。
    
    The map must be rectangular.
    
- 地図は壁で閉じていなければならない／囲まれていなければならない。そうでない場合、プログラムはエラーを返さなければならない。
    
    The map must be closed/surrounded by walls. If it’s not, the program must return an error.
    
- 地図に有効なパスがあるかどうかをチェックする必要はない。
    
    You don’t have to check if there’s a valid path in the map
    
- 上記の規則を守る限り、どんな種類の地図でもパースできるようにしなければならない。
    
    You must be able to parse any kind of map, as long as it respects the above rules.
    
- もし、ファイルに何らかの設定ミスがあった場合、プログラムはきれいな形で終了し、"Error\n "に続いて任意の明示的なエラーメッセージを返さなければなりません。
    
    If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.
    

## Bonus part

通常は、自分でオリジナルの追加機能を開発することが推奨されます。しかし、この後、もっと面白いグラフィックプロジェクトが待っています。それらはあなたを待っています! この課題ではあまり時間を無駄にしないように!

Usually, you would be encouraged to develop your own original extra features. However,
there will be much more interesting graphic projects later. They are waiting for you!!
Don’t lose too much time on this assignment!

ボーナスパートを完成させるために他の機能を使用することは、評価の際にその使用が正当化される限り、許されます。賢くなりましょう

You are allowed to use other functions to complete the bonus part as long as their
use is justified during your evaluation. Be smart!

次のような場合、追加ポイントが得られます。

- 敵のパトロールに触れると、プレイヤーが負けるようにする。
    
    Make the player lose when they touch an enemy patrol
    
- スプライトのアニメーションを追加する。
    
    Add some sprite animation.
    
- 移動回数をシェルに書かず、直接画面に表示する。
    
    Display the movement count directly on screen instead of writing it in the shell
