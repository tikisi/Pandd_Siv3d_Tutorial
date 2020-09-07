﻿# include <Siv3D.hpp> // OpenSiv3D v0.4.3

struct Character {
    int posX, posY;
    int width, height;
    int life;
};

// プレイヤー
Character player;
void PlayerInit();
void PlayerUpdate();
void PlayerDraw();

// 敵
#define ENEMY_NUM 20
Character enemy[ENEMY_NUM];
void enemeyInit();
void enemeyUpdate();
void enemyDraw();

// 弾
#define SHOT_NUM 20
Character shot[SHOT_NUM];
void shotInit();
void shotUpdate();
void shotDraw();

void Main()
{
    PlayerInit();
    enemeyInit();
    shotInit();

    while (System::Update())
    {
        PlayerUpdate();
        enemeyUpdate();
        shotUpdate();
        PlayerDraw();
        enemyDraw();
        shotDraw();
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

void enemeyInit() {
    for (int i = 0; i < ENEMY_NUM; i++) {
        enemy[i].height = 50;
        enemy[i].width = 50;
        enemy[i].posX = Scene::Width();
        enemy[i].posY = Random<int>(Scene::Height() - enemy[i].height);
        enemy[i].life = 0;
    }
}

void enemeyUpdate() {
    // 敵の出現
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (enemy[i].life == 0) {
            if (Random<int>(150) == 0) {
                enemy[i].life = 5;
            }
        }
    }

    // 移動
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (enemy[i].life != 0) {
            enemy[i].posX -= 6;
        }
    }

    // 画面外に出たら
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (enemy[i].life != 0) {
            if (enemy[i].posX + enemy[i].width < 0) {
                enemy[i].posX = Scene::Width();
                enemy[i].posY = Random<int>(Scene::Height() - enemy[i].height);
                enemy[i].life = 0;
            }
        }
    }
}

void enemyDraw() {
    for (int i = 0; i < ENEMY_NUM; i++) {
        if (enemy[i].life != 0) {
            Rect(enemy[i].posX, enemy[i].posY, enemy[i].width, enemy[i].height).draw(Palette::Red);
        }
    }
}

void shotInit() {
    for (int i = 0; i < SHOT_NUM; i++) {
        shot[i].height = 10;
        shot[i].width = 10;
        shot[i].posX = 0;
        shot[i].posY = 0;
        shot[i].life = 0;
    }
}

void shotUpdate() {
    // 出現
    if (KeySpace.down()) {
        for (int i = 0; i < SHOT_NUM; i++) {
            if (shot[i].life == 0) {
                shot[i].life = 1;
                shot[i].posX = player.posX + player.width;
                shot[i].posY = player.posY + player.height / 2;
                break;
            }
        }
    }

    // 移動
    for (int i = 0; i < SHOT_NUM; i++) {
        if (shot[i].life != 0) {
            shot[i].posX += 6;
        }
    }

    // 画面外に出たら
    for(int i = 0; i < SHOT_NUM; i++) {
        if (shot[i].posX > Scene::Width()) {
            shot[i].life = 0;
            shot[i].posX = 0;
            shot[i].posY = 0;
        }
    }
}

void shotDraw() {
    for(int i = 0; i < SHOT_NUM; i++) {
        if(shot[i].life != 0) {
            Rect(shot[i].posX, shot[i].posY, shot[i].width, shot[i].height).draw(Palette::White);
        }
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
