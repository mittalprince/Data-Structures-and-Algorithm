/* 
Advantage:
1. since in this we attach a single evnthandler to parent, so avoid many eventhandle hence save memory
2. writing less code
3. DOM Manipulation

Disadvantage
1. Can not use stopPropagation
*/

document.querySelector("#category").addEventListener('click', (e) => {
  console.log(e.target);
  if (e.target.tagName == 'LI') {
    window.location.href = "/" + e.target.id;
  }
});

document.querySelector("#form").addEventListener('keyup', (e) => {
  console.log(e);
  if (e.target.dataset.uppercase != undefined) {
    e.target.value = e.target.value.toUpperCase();
  }
})