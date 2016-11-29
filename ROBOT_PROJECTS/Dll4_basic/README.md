# GoSimu DLL Sample

Go Simulation!では、ユーザープログラムをDLLで作成して使用することができます。
ここではDLLのサンプルプログラムをまとめました。

## サンプルDLLのビルド方法

DLL作成用のサンプルプロジェクトは以下にあります。
DllCont4user/DllCont4.sln
Visual Studio(C++) 2008以降で使用できます。

そのままビルドすると、ReleaseフォルダにDllCont4.dllが作成されます。

作成されたDllCont4.dllをProgramフォルダの下にコピーしてください。


## サンプルDLLの実行方法

Go Simulation!を設計モードにし、Dll4_basicプロジェクトを開いてください。
コマンドウィンドウを出してrunと入力すると、このDLLが実行されます。
何故ならば、Program/main.txtに下記のように記述されているため、DllCont4.dllが実行されるからです。
```text:main.txt
dll_run(DllCont4)
```

## サンプルDLLの改造方法

動作確認ができたら、DLLのソースコードをみてみましょう。
DllCont4user/DllCont4/main_11TestDll4_basic.cpp
がメインとなるソースです。
（注）他のソースコードは書き換えないでください

Dll4_Run関数の中をみると、以下のようになっています。
```cpp:main_11TestDll4_basic.cpp
//[[[ select a test function ]]]
testMotionDSensor(sim);
//	testAnalogJoypad(sim);
//	testCamera(sim);
//	testTorqueRef(sim);
//	testZmpCalcInDll(sim);
```


例えば以下のようにするとアナログジョイパッドのテストができます。
```cpp:main_11TestDll4_basic.cpp
//[[[ select a test function ]]]
//	testMotionDSensor(sim);
testAnalogJoypad(sim);
//	testCamera(sim);
//	testTorqueRef(sim);
//	testZmpCalcInDll(sim);
```

具体的な処理はソースコードのコメント文を参照ください。



