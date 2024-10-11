# Nain. A fast, lightweight and general-purpose Programming Language

Nain is built from the ground up to be fast, top-level and in result, a game changer for programming.

## Features

- Fast
Nain is a JIT compiled language. The speeds are similar to C++ and Rust, two very fast languages.
- Lightweight
Nain is a very lightweight language.
In fact, it has no dependencies, and it runs ont th e Nain VM. So you can run Nain anywhere. On phone, desktop (windows,mac,linux,freebsd and ChromeOS), web IoT and TVs.
- General purpose
Nain gives you the power to do anything anywhere.
From making Webs, games, to creating a new programming language.
- Multi-paradigm
Nain is a multi-paradigm language.
So you can use OOP (Object Oriented Programming), Functional (Functional Programming), Procedural (Procedural Programming) and more.
- Easy to learn
Nain syntax is carefully crafted to be easy to learn.

## Getting started

The first thing you'll want to do is download [the nain compiler](github.com/theatualmariluski/nain)
You can also install it on your OS's package manager.

--------------------------------------------------------------------------------------------
| **Linux** | **Mac**                                              | **Windows**                                                        |
|-----------|--------------------------------------------|---------------------------------|
|Brew `brew install nain`| Brew can also be used on Mac. | Download from the GitHub repository. |
|Nix OS `nix-env -iA nixos.nain`| ---------  | ----------------- |

After you have installed the compiler, make a new directory and start a new project with:
```bash
neopack init
```
It will ask you the following questions:

* What is the name of your project?
* What is the person or company that will be the owner of the project?
* Do you want to use a license?
* Do you want a Git repository?
* Do you want the extra files for a more complete project (README, SECURITY.md, CONTRIBUTING.md, CODE_OF_CONDUCT.md .gitignore, editor and prettier rc etc.)?
* Do you want to publish the project on neopack?

Neopack is the default Nain package manager.

Congratulations!
You have just created your first Nain project.

Now, neopack generated this project for you:
```filetree
my-project
    .gitignore
    .git
    CODE_OF_CONDUCT.md
    CONTRIBUTING.md
    LICENSE
    README.md
    SECURITY.md
    src
      main.nain
    neopack.toml
    deps.lock
    compconfig.toml
    bin
      app.npkportpkg // .npkportpkg stands for NeoPack portable package file
```
now, go to the `src` directory and open the `main.nain` file.
Then, go to the docs on this foldes and follow the beginners tutorial at the `docs/basics` folder.

## Contributing

Contributions are welcome!
Please, read the [contributing guidelines](CONTRIBUTING.md) and the [code of conduct](CODE_OF_CONDUCT.md).
