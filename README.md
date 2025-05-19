# CS106L Assignments 

- 代码仓库克隆自[cs106l-assignments](https://github.com/cs106l/cs106l-assignments/tree/792f7c5b69479dbbd1002ba8fc1b55bc34b77187)（2025 Winter Version）。
- C++ 相关的个人笔记（不严格遵循 CS106L 的授课顺序和内容，同时兼顾本校的 OOP 课程）：[note.noughtq.top/lang/cpp](https://note.noughtq.top/lang/cpp/)
- 简要感受：
    - 覆盖面很广，基本上讲清楚了 C++ 的核心特征，并且涉及到很多新标准中（尤指 C++11 后的标准）引入的新语法，比如 range、view、concept、可变模板等，着实让我大开眼界。
    - 作业不难，主要起到巩固所学知识的作用。代码能力好的同学不会在这些作业上花费太多时间。
    - 再来看本校的 OOP 课程：
        - 讲的内容老掉牙（只讲到 C++11 标准之前的内容），并且专注于琐碎的语法细节；
        - PPT 的内容缺乏严谨的逻辑（也就是说光看 PPT 无法搞明白老师要讲什么，对我这种上课一个字不听的同学很不友好）；
        - 某些老师布置的作业内容混乱，令人迷惑。
        - ...

        这样的课我实在听不下去，所以我抽出一些时间来浅浅学了下大名鼎鼎的 CS106L。一句话感受就是：“不虚此行！”


## 进度

- [x] assign0
- [x] assign1
- [x] assign2
- [x] assign3
- [x] assign4
- [x] assign5
- [x] assign6
- [x] assign7


## 注意事项

- 可能是因为我的 Python 版本过新（3.13.3），在运行 autograder 时会发生类似以下报错（以 assign1 为例，实际上每个 assign 都会发生这样的错误）：

    ```
    ./main          
    ⏳ Installing autograder packages (this may take a few minutes)...

    ERROR: Can not perform a '--user' install. User site-packages are not visible in this virtualenv.
    Traceback (most recent call last):
    File "~/Stanford-CS106L/2025winter/assignments/assign1/autograder/autograder.py", line 1, in <module>
        from utils import Autograder
    File "~/Stanford-CS106L/2025winter/assignments/assign1/autograder/utils.py", line 104, in <module>
        _install_requirements()
        ~~~~~~~~~~~~~~~~~~~~~^^
    File "~/Stanford-CS106L/2025winter/assignments/assign1/autograder/utils.py", line 91, in _install_requirements
        _install_requirement(package)
        ~~~~~~~~~~~~~~~~~~~~^^^^^^^^^
    File "~/Stanford-CS106L/2025winter/assignments/assign1/autograder/utils.py", line 57, in _install_requirement
        subprocess.check_call(
        ~~~~~~~~~~~~~~~~~~~~~^
            [sys.executable, "-m", "pip", "install", package],
            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            stdout=subprocess.DEVNULL,
            ^^^^^^^^^^^^^^^^^^^^^^^^^^
        )
        ^
    File "/opt/homebrew/Cellar/python@3.13/3.13.3/Frameworks/Python.framework/Versions/3.13/lib/python3.13/subprocess.py", line 419, in check_call
        raise CalledProcessError(retcode, cmd)
    subprocess.CalledProcessError: Command '['~/Stanford-CS106L/2025winter/assignments/assign1/autograder/bin/python', '-m', 'pip', 'install', 'colorama==0.4.6']' returned non-zero exit status 1.
    ```

    - 解决方案：在每个 assign 下都有一个 autograder 目录，进入该目录后修改 utils.py，找到第58行和第96行，分别添加 `"--no-user"`（已完成的 assign 均做好这一修改）。

        ```py
        # Line 58
        [sys.executable, "-m", "pip", "install", "--no-user", package],

        # Line 96
        [sys.executable, "-m", "pip", "install", "--no-user", "-r", REQUIREMENTS],
        ```

- 个人感觉 assign1 代码有一个小问题：题目要求我们完成的三个函数都是按值传递的，这样就没发直接修改参数，应该改为**按引用传递**。

