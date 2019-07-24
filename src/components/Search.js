import React from 'react';


function Search(props) {
  return (
    <form
    style={{marginBottom:"2rem"}}
    onSubmit={(e)=>{
      e.preventDefault();
      props.onSubmit(e.target.recipeName.value);
    }} >
      <input
      className="form__input" type ="text" name="recipeName" />
      <input
      className="form__button" type="submit"></input>
    </form>
  );
}

export default Search;
