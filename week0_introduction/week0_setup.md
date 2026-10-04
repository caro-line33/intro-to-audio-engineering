# Getting Started

## 1: Installing Git

Follow these steps to install Git and download the workshop files.
You do not need a GitHub account.

<details>
<summary> Instructions for Windows </summary>

1. Go to [git-scm.com/downloads](https://git-scm.com/downloads).
2. Download and run the Windows installer.
3. Follow the installation prompts. The default options are generally fine.
4. Close and reopen Command Prompt or VS Code.
5. Run this command to verify the installation:

   ```bash
   git --version
   ```
</details>

<details>
<summary> Instructions for macOS </summary>

1. Open **Terminal**.
2. Run:

   ```bash
   git --version
   ```

3. If prompted, install Apple's command-line tools.
4. After installation, run `git --version` again.

</details>

## 2. Downloading the Workshop Files

We will use **Git** to download the workshop files and keep them up to date:

- **`git clone`** downloads the repository for the first time.
- **`git pull`** downloads updates to an existing copy.

<details>
<summary>Project Folder Structure</summary>

Keep your work separate from the course materials so you can download updates without conflicts. I recommend this structure:

```text
audio_intro/
├── tutorials/       # Tutorials, examples, and starter code
└── my-projects/     # Your code and experiments
```

When working on an example, copy it into `my-projects` before making changes.

The commands in the download section below will create these folders for you.

</details>

<details>
<summary>Navigating the Command Line (Optional)</summary>

This section introduces basic command-line navigation. Feel free to skip it if you are already familiar.

Open **Command Prompt or PowerShell** on Windows, or **Terminal** on macOS.

### Check your current location

Your terminal works within a current folder. Use these commands to see where you are and what is inside it:

| Action | Windows Command Prompt | Windows PowerShell | macOS Terminal |
|---|---|---|---|
| Show your current folder | `cd` | `pwd` | `pwd` |
| List files and folders | `dir` | `ls` | `ls` |

### Move between folders

Use `cd` (change directory) followed by a folder name to enter a folder inside your current location:

```bash
cd Documents
```

To go up one folder:

```bash
cd ..
```

For folder names containing spaces, use quotation marks:

```bash
cd "My Projects"
```

You can type part of a folder name and press **Tab** to autocomplete it.

### Go directly to a location

You can also use a full path. For example, to go to your Desktop:

**Windows Command Prompt:**

```cmd
cd /d "C:\Users\YOUR-USERNAME\Desktop"
```

**Windows PowerShell:**

```powershell
cd "C:\Users\YOUR-USERNAME\Desktop"
```

**macOS:**

```bash
cd ~/Desktop
```

Replace the Windows example with your actual folder path. Your Desktop may be inside OneDrive. On macOS, `~` means your home folder.

### Create a folder

Use `mkdir` to create a folder, then `cd` to enter it:

```bash
mkdir example-folder
cd example-folder
```

</details>

<details>
<summary>Download the Repository</summary>

### 1. Choose a location

Open a terminal and navigate to wherever you want to store the workshop project, such as your Desktop or Documents folder.

### 2. Create the project folder

Run these commands one at a time:

```bash
mkdir audio_intro
cd audio_intro
```

If you already created `audio_intro`, just enter it using `cd`.

### 3. Download the course materials

Run:

```bash
git clone https://github.com/caro-line33/intro-to-audio-engineering.git tutorials
```

Git automatically creates the `tutorials` folder and downloads the repository into it. You do not need to create that folder yourself.

### 4. Create a folder for your own work

While still inside `audio_intro`, run:

```bash
mkdir my-projects
```

Your project now has two folders: `tutorials` for the course materials and `my-projects` for your own work.

You only need to complete this setup once.

</details>

<details>
<summary>Download Future Updates</summary>

When new lessons or corrections are available, open a terminal and navigate to your `audio_intro/tutorials` folder.

If you are currently inside `audio_intro`, run:

```bash
cd tutorials
```

Then download the latest updates:

```bash
git pull
```

Always run `git pull` from inside the `tutorials` repository folder. You do not need to run `git clone` again.

Keep your changes in `my-projects` so updates to the course materials do not conflict with your work.

</details>

## 3. Viewing Markdown Files in VSCode

These tutorials are written as .md files. If this file looks like a plain text file without formatting, then you need to change some settings. In the top-right corner while in a .md file, select `text editor` --> `set default for '*.md'` --> `Markdown Preview`. It should now have formatting.