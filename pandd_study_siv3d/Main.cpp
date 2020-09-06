# include <Siv3D.hpp> // OpenSiv3D v0.4.3

void Main()
{
    int posX = 20;
    int posY = 40;

    while (System::Update())
    {
        if (KeyRight.pressed()) {
            posX += 5;
        }
        if (KeyLeft.pressed()) {
            posX -= 5;
        }
        if (KeyUp.pressed()) {
            posY -= 5;
        }
        if(KeyDown.pressed()) {
            posY += 5;
        }

        if(posX < 0) posX = 0;
        if(posX + 80 > Scene::Width()) posX = 80 + Scene::Width();
        if(posY < 0) posY = 0;
        if(posY + 80 < Scene::Height()) posY = 80 + Scene::Height();


        Rect(posX, posY, 80, 80).draw(Palette::Orange);
    }
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
