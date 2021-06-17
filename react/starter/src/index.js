


function main() {
  return xs.periodic(1000)
    .fold(prev => prev + 1, 0)
    .map(i => `seconds elapsed: ${i}`)
}

function domDriver(text$){
  text$.subscribe({
    next: str => {
      const elem = document.querySelector('#app');
      elem.textContent = str;
    }
  });

}

function logDriver(text$){
  text$.subscribe({
    next: str => {
      console.log(str);
    }
  });

}
const sink =main();
domDriver(sink);
logDriver(sink);
