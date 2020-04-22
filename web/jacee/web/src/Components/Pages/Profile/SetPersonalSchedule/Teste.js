import React, { useState, useEffect } from "react";

function Teste(props) {
  const [count, setCount] = useState(0);
  const [array, setArray] = useState([1, 2, 3, 4, 5]);

  useEffect(() => {
    // console.log("Count", count);
    console.log("Array", array);
  }, [array]);

  function add() {
    let a = array;
    a = a.concat(1);
    setArray(a);
    //setArray(array.concat(6));
    // console.log("Add", array);
    // setCount(count + 1);
    // console.log("Add", count);
  }

  function reset() {
    setArray([1, 2, 3, 4, 5]);

    // console.log("Reset", array);
    // setCount(0);
    // console.log("Reset", count);
  }

  return (
    <>
      <div onClick={() => add()} style={{ color: "black" }}>
        Add
      </div>
      <div onClick={() => reset()} style={{ color: "black" }}>
        Reset
      </div>
    </>
  );
}

export default Teste;
