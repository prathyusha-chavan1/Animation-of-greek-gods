import React from 'react';
import Recipe from './Recipe';

function Recipes(props) {
  return (
    
    <div className="container">
      <div className="row">
    
     {
       props.recipes.map(recipe=><Recipe key={recipe.recipe_id} data={recipe} />)
     }
    </div>
     
     </div>
  );
}

export default Recipes;