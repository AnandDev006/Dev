const menu = document.getElementById("menu");
const nav = document.getElementById("nav");
const exit = document.getElementById("exit");

menu.addEventListener("click", (e) => {
  nav.classList.remove("hide-mobile");
  e.preventDefault();
});

exit.addEventListener("click", (e) => {
  nav.classList.add("hide-mobile");
  e.preventDefault();
});
