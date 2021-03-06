# GoSimu DLL Sample

Go Simulation!では、ユーザープログラムをDLLで作成して使用することができます。
ここではDLLのサンプルプログラムをまとめました。

## サンプルDLLのビルド方法

DLL作成用のサンプルプロジェクトは以下にあります。
DllCont5/DllCont5.sln
Visual Studio(C++) 2008以降で使用できます。

そのままビルドすると、ReleaseフォルダにDllCont5.dllが作成されます。

作成されたDllCont5.dllを
(ロボットプロジェクト)/Program
フォルダの下にコピーしてください。


## サンプルDLLの実行方法

Go Simulation!を設計モードにし、Dll5_basicプロジェクトを開いてください。
コマンドウィンドウを出してrunと入力すると、このDLLが実行されます。
何故ならば、Program/main.txtに下記のように記述されているため、DllCont5.dllが実行されるからです。
```text:main.txt
dll_run(DllCont5)
```

## サンプルDLLの改造方法

動作確認ができたら、DLLのソースコードをみてみましょう。
DllCont5/DllCont5/dllmain.cpp
がメインとなるソースです。
（注）他のソースコードは書き換えないでください

Dll_Run関数の中をみると、以下のようになっています。
```cpp:dllmain.cpp
	//[[[ select the test function ]]]
	testBasic();
	//testDistanceSensor();
	//testAnalogJoypad();
	//testCamera();
	//testVelRef();
	//testTorqueRef();
	//testZmpCalcInDll();
	//testFootTouchSensor();
	//testIk();
	//testContact();
	//testTcpClient();
```


例えば以下のようにするとアナログジョイパッドのテストができます。
```cpp:dllmain.cpp
//[[[ select a test function ]]]
	//testBasic();
	//testDistanceSensor();
	testAnalogJoypad();
```

具体的な処理はソースコードのコメント文を参照ください。



