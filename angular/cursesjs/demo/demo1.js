window.addEventListener("load", async () => {
  // Polute the global namespace, because programming is fun.
  for (const k in curses)
    window[k] = curses[k]

  document.getElementById("preload").remove()
  /*
  // * /
  const scr = initscr({
    container: "#stage",
    min_height: 30,
    min_width: 60,
    font: {
      type: "ttf",
      name: "Source Code Pro",
      height: 14,
      line_spacing: 1
    },
    require_focus: false
  });
  // */
  /*
  */
  curses.initscr({
    container: document.getElementById("my-canvas"),
    height: 25,
    width: 80,
    font: {
      type: "bmp",
      name: "myfont.png",
      height: 16,
      width: 9,
      line_spacing: 0,
      use_char_cache: true,
    },
  });
  // Define colors we can use later.
  curses.init_pair(1, COLOR_RED, COLOR_BLACK);
  // Main loop
  while (1) {
    // Clear the screen.
    curses.clear();
    // Tell the user what to do.
    curses.addstr(0, 0, "Please hit ");
    curses.addstr("any key", COLOR_PAIR(1) | A_BOLD);
    curses.addstr(" to have fun.");
    curses.refresh();
    // Wait for the user to press a key.
    const c = await getch();
    // Do something depending on which key was pressed.
    curses.move(2, 0);
    if (c == KEY_F) {
      curses.addstr("F is for the ");
      curses.addstr("friends", A_UNDERLINE);
      curses.addstr(" that do stuff together.");
    }
    else {
      curses.addstr("I don't know about that key.");
    }
  }
})
