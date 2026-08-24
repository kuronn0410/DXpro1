scene-manager.md

# シーンの管理

## 目的

---

## 流れ


### 初期化
Initialize.cppで
sceneManager.Initialize(SceneType::Title);を宣言
↓
sceneManagerのInitializeで現在のシーンをTitleSceneに設定
↓
現在のシーンのInitializeを呼び出す

### 更新
現在設定されてるシーンのUpdateを呼び出す

### 描画
現在設定されてるシーンのDrawを呼び出す


### シーン切り替え
それぞれのシーン内で、次に遷移するシーンを設定する
↓
sceneManagerが前のシーンの終了処理を行い次のシーンに切り替える

Title→Home
Home→StageSelect
Home→PartySelect
StageSelect→Battle
Battle→Reward
Reward→Home

### 終了

---
## 所有関係

---


## 参照関係

---

## 依存関係

---
## ライフタイム

sceneManager : ゲーム開始時に生成され、ゲーム終了時に破棄される。
それぞれの処理を行い : それぞれのシーンのInitializeで生成され、次のシーン生成前に終了処理で破棄される。


---

## 現在理解が浅い点

---