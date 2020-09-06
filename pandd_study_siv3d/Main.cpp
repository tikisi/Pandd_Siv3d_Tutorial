# include <Siv3D.hpp> // OpenSiv3D v0.4.3

struct Character {
    int posX, posY;
    int width, height;
};

// プレイヤー
Character player;
void PlayerInit();
void PlayerUpdate();
void PlayerDraw();

void Main()
{
    PlayerInit();

    while (System::Update())
    {
        PlayerUpdate();
        PlayerDraw();
    }
}

void PlayerInit() {
    player.posX = 0;
    player.posY = 300;
    player.width = 60;
    player.height = 60;
}

void PlayerUpdate() {
    // プレイヤーの移動
    if (KeyRight.pressed()) player.posX += 5;
    if (KeyLeft.pressed()) player.posX -= 5;
    if (KeyUp.pressed()) player.posY -= 5;
    if (KeyDown.pressed()) player.posY += 5;

    // 画面外処理
    if (player.posX < 0) player.posX = 0;
    if (player.posX + player.width > Scene::Width()) player.posX = Scene::Width() - player.width;
    if (player.posY < 0) player.posY = 0;
    if (player.posY + player.height > Scene::Height()) player.posY = Scene::Height() - player.height;
}

void PlayerDraw() {
    Rect(player.posX, player.posY, player.width, player.height).draw(Palette::Orange);
}


//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D ユーザコミュニティ Slack への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
